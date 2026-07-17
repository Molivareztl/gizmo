#include "jugador.h"

jugador::jugador(){
    en_el_suelo = true;
    estado_vida = true;
    input = true;
    atravesar_puerta = false;
    opcion = 0;
    direccion = {2,0};
    atlas = {0,0,16,16};
    habitaciones_pasadas = 0;
    velocidad.x = 0.0f;
    velocidad.y = 0.0f;
    hitbox = {0, 0, 32, 32};
    puede_disparar = false;
    municion ={5, 5};
    textura.reserve(2);
};
void jugador::ubicar(int posx, int posy)
{
    hitbox.x = posx; 
    hitbox.y = posy;
    estado_vida = true;
    input = false;
    atravesar_puerta = false;
    velocidad.x = 0;
    velocidad.y = 0;
    vaciar();
}
void jugador::cargar( Texture2D _textura)
{
    textura.push_back(_textura);
}
void jugador::cargar( Sound _efecto)
{
    efectos.push_back(_efecto);
}
void jugador::dibujar(){
    switch (opcion)//mostrar la munición
    {
    case 0:
        DrawText(TextFormat("%i", municion[opcion]),hitbox.x + 8,hitbox.y - hitbox.width,32,PINK);
        DrawTexture(textura[2],0,0,WHITE);
        break;
    case 1:
        DrawText(TextFormat("%i", municion[opcion]),hitbox.x + 8,hitbox.y - hitbox.width,32,GREEN);
        DrawTexture(textura[1],0,0,WHITE);
        break;
    }//cambiar el atlas

    if(velocidad.y > 0.3f)
    {
        atlas.y = 16;
    }else
    {
        atlas.y = 0;
    }//mostrar el personaje

    DrawTexturePro(textura[0], Rectangle{atlas.x, atlas.y,atlas.width,15.99},Rectangle{hitbox.x,hitbox.y,hitbox.width,hitbox.height},Vector2{0,0},0,WHITE);
    
}
void jugador::disparar(){
    if(municion[opcion] != 0)
    {
    proyectiles.emplace_back(hitbox, direccion ,opcion);
    municion[opcion] -= 1;
    PlaySound(efectos[1]);
    }
}
void jugador::actualizar(){
    hitbox.x += velocidad.x;
    hitbox.y += velocidad.y;
    direccion.x = velocidad.x;
    direccion.y = velocidad.y;
    if (input == true)
    {
    if(IsKeyPressed(KEY_ONE))
    {
        opcion = 0;
    }else if(IsKeyPressed(KEY_TWO))
    {
        opcion = 1;
    }
    if(IsKeyDown(KEY_RIGHT))
    {
        velocidad.x = 3.0f;
        atlas.width = 16;
    }else if(IsKeyDown(KEY_LEFT))
    {
        velocidad.x = -3.0f;
        atlas.width = -16;
    }else {velocidad.x = 0.0f;
    }
}
    if (en_el_suelo == true)
    {
        if (IsKeyDown(KEY_UP))
        {
            en_el_suelo = true;
            PlaySound(efectos[0]);
            velocidad.y = -3.5f;
        }   
    }else
    {
        velocidad.y += 0.1f;
    }
    if(IsKeyDown(KEY_SPACE) && puede_disparar == true)
    {
        puede_disparar = false;
        disparar();
    }else if (!IsKeyDown(KEY_SPACE))
    {
        puede_disparar = true;
    }
    en_el_suelo = false;
    
}

void jugador::colisiona(ladrillo collision){
    if(CheckCollisionRecs(hitbox, collision.hitbox) == true)
    {
        Rectangle overlap = GetCollisionRec(hitbox, collision.hitbox);
        if (overlap.width < overlap.height)
        {
            if (hitbox.x < collision.hitbox.x)
            {
                hitbox.x -= overlap.width;
            }else
            {
                hitbox.x += overlap.width;
            }
        }
        if (overlap.width > overlap.height)
        {
            velocidad.y = 0.0f;
            if (hitbox.y < collision.hitbox.y)
            {
                hitbox.y -= overlap.height;
                en_el_suelo = true;
                input = true;
            }else
            {
                hitbox.y += overlap.height;
            }
        }

        if (collision.puede_lastimar() == true)
        {
            estado_vida = false;
        }
        if (collision.puede_pasar() == true)
        {
            atravesar_puerta = true;
            habitaciones_pasadas += 1;
        }
    }
}
void jugador::vaciar()
{
    proyectiles.clear();
    municion = {5, 5};
}

void jugador::sumar_punto()
{
    habitaciones_pasadas ++;
}
int jugador::mostrar_punto()
{
    return habitaciones_pasadas;
}

bool jugador::colision_lastima()
{
    return estado_vida;
}

bool jugador::colision_puerta()
{
    return atravesar_puerta;
}

Vector2 jugador::posicion_actual()
{
    return Vector2{hitbox.x, hitbox.y};
}

