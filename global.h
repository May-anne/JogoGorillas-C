#ifndef GLOBAL_H
    #define GLOBAL_H

    #define Y 32
    #define X 140
    int changeColor(char x[3][10], char y[]);
    void ranking(void);
    void pickLevel (void);
    void keepPlaying(void);
    int play(int nivel);
    void buildMap(int nivel);
    int throwBanana(int ang, int vel, int jogador);

    typedef struct{
    char *nome;
    char angulo[5], velocidade[5];
    unsigned short angtoInt, veltoInt, placar;
    } Play;

#endif