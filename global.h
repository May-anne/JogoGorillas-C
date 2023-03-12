#ifndef GLOBAL_H
    #define GLOBAL_H

    int mudarCor(char x[3][10], char y[]);
    void ranking(void);
    int picklevel (void);
    int play(int nivel);
    void buildMapa(int nivel);
    int colisaoPredio (int Hpredios [], int y, int x);
    extern int Hpredios[8];

#endif