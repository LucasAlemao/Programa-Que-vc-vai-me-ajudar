#include<stdio.h>
#include<stdlib.h>

    /*FUNCAO RAIZ CUBICA*/
    float RaizCubica (float x){

        float r, rant, erro;
        float eps = 10e-8;

        erro = x;
        r = x;
        rant = r;

        while (erro >= eps){
            r = (2*rant)/3 + x/(3*rant*rant);
            if (rant != 0){
                erro = r - rant;
                if (erro < 0)
                    erro = -erro;
            }
            else{
                if (r == 0)
                    erro = 0;
                else
                    erro = 1;
            }
            rant = r;
        }
        return r;
        }

    /*FUNCAO CHAO*/
     chao(float y){
        float j = 0;
        while (j<y){
            j = j+1;
        }
        if (j > y)
            j = j - 1;
        return j;
    }

    /*FUNCAO NOVA CAIXA*/
    float NovaCaixa(float box){
        float rif;
        rif = 9821.0 * RaizCubica(box) + 0.211327;
        box = rif - chao( rif );

        return box;
        }

    int main (){

        int semente, i, n;
        float teto, derrota, vitoria, pontuacaoj, pontuacaom, caixa, carta, cartaj, cartam;
        teto  = 0.5;

        printf("SIMULACAO SEVEN n' HALF\n");

        printf("Entre com a semente:  ");
        scanf ("%d", &semente);

        /*INTRODUZINDO A CAIXA*/

        caixa = semente;
        while (semente !=0){
            caixa = caixa/10;
            semente = semente/10;
        }
        /*LACO DOS TETOS*/
        while (teto <= 7.5){
            n = 0;
            derrota = 0;
            vitoria = 0;

            /*LACO DOS 10000 JOGOS*/
            for (i=1; i<=10000; i++){
                pontuacaoj = 0;
                pontuacaom = 0;
                cartam = 0;
                cartaj = 0;

                /*JOGADOR COMPRA CARTAS*/
                while(pontuacaoj < teto){
                    carta = chao(caixa*10 + 1);
                    if (carta <=7)
                        pontuacaoj = pontuacaoj + carta;
                    else
                        pontuacaoj = pontuacaoj + 0.5;
                    cartaj = cartaj + 1;
                    caixa = NovaCaixa(caixa);
                }

                /*SE JOGADOR NAO ESTOROU, CAIXA COMPRA CARTAS*/
                if (pontuacaoj > 7.5)
                    vitoria = vitoria + 1;
                else{
                     while (pontuacaom < pontuacaoj){
                        carta = chao(caixa*10 + 1);
                        if (carta <=7)
                            pontuacaom = pontuacaom + carta;
                        else
                            pontuacaom = pontuacaom + 0.5;
                        cartam = cartam + 1;
                        caixa = NovaCaixa(caixa);
                     }
                      /*ANALISE DE CASOS*/
                      /*SE CAIXA ESTOROU -> DERROTA*/
                    if (pontuacaom > 7.5)
                        derrota = derrota + 1;

                    /*SE CAIXA NAO ESTOROU E VENCEU NA PONTUACAO -> VITORIA*/
                    if ((pontuacaom > pontuacaoj)&&(pontuacaom <= 7.5))
                        vitoria = vitoria + 1;

                    /*SE AMBOS TIVEREM MESMA PONTUACAO*/
                    if (pontuacaom == pontuacaoj){
                        if (cartam > cartaj)
                            derrota = derrota + 1;
                        else
                            vitoria = vitoria + 1;
                        if (cartam == cartaj){
                            carta = chao(caixa*10 + 1);
                            if (carta <=7)
                                pontuacaom = pontuacaom + carta;
                            else
                                pontuacaom = pontuacaom + 0.5;
                            cartam = cartam + 1;
                            caixa = NovaCaixa(caixa);
                            /*ANALISE DENTRO DO CASO EM QUE CAIXA ARRISCOU COMPRAR MAIS 1 CARTA*/
                            if (pontuacaom > 7.5)
                                derrota = derrota + 1;
                            else
                                vitoria = vitoria + 1;
                            }
                    }
                }
            }
        printf ("%0.1f  ", teto);
        printf("%.0f  ", derrota);

        while (n < chao( 100*(derrota/10000) + 0.5 )){
            printf("*");
            n = n + 1;
        }

        printf("\n");

        teto = teto + 0.5;
    }

        return 0;

}

