// Version du GLSL

#version 140


// Entr�e

in vec2 coordTexture;


// Uniform

uniform sampler2D text;


// Sortie 

out vec4 out_Color;


// Fonction main

void main()
{
    // Couleur du pixel

    out_Color = texture(text, coordTexture);
}
