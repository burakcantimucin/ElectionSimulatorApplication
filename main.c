#include <stdio.h>
#include <stdlib.h>

int main()
{
    int parti, sandalye, i, j, k=0;
    printf("Secime kac parti katilacak: ");
    scanf("%d",&parti);
    printf("Mecliste kac sandalye var: ");
    scanf("%d",&sandalye);
    printf("\n");
    float partiToplamOy[parti], vekilHesapla[parti][sandalye], vekilSirala[parti*sandalye], gecici;
    for(i=0;i<parti;i++)
    {
        printf("%d. partinin aldigi toplam oy: ",i+1);
        scanf("%f",&partiToplamOy[i]);
    }
    printf("\n");
    for(i=0;i<parti;i++)
    {
        for(j=0;j<sandalye;j++)
        {
            vekilHesapla[i][j]=partiToplamOy[i]/(j+1);
            printf("%d. partinin %2d. siradaki adayinin oyu: %.0f\n",i+1,j+1,vekilHesapla[i][j]);
            vekilSirala[k]=vekilHesapla[i][j];
            k++;
        }
        printf("\n");
    }
    for(i=0;i<parti*sandalye;i++)
    {
        for(j=0;j<parti*sandalye;j++)
        {
            if(vekilSirala[i]>vekilSirala[j])
            {
                gecici=vekilSirala[i];
                vekilSirala[i]=vekilSirala[j];
                vekilSirala[j]=gecici;
            }
        }
    }
    for(i=0;i<sandalye;i++)
    {
        printf("%d. parlamenterin aldigi oy: %.0f\n",i+1,vekilSirala[i]);
    }
    return 0;
}
