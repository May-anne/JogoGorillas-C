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
    int placar=0;
    char angulo[5];
    char velocidade[5];
    int angtoInt;
    int veltoInt;
    } Play;

#endif