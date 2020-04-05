//
//  Poke_card.c
//  poke_card
//
//  Created by 張鶴 on 2020/4/5.
//  Copyright © 2020 張鶴. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define card_number 52
#define players 4

void shuffle(void);
void give_card(void);
void print_card(int);
void sort_card(void);
void swag(int *,int *);
void sort_card(void);

int cards[52] = {0},player1[13]={0},player2[13]={0},player3[13]={0},player4[13]={0};

int main(){
    int *p;
    p = cards;
    for(int i=0;i<card_number;i++){
        *(p+i) = i+1;
    }
    shuffle();
    give_card();
    sort_card();
    printf("player1:");
    for(int i=0;i<13;i++){
        print_card(player1[i]);
    }
    printf("\n\n");
    printf("player2:");
    for(int i=0;i<13;i++){
        print_card(player2[i]);
    }
    printf("\n\n");
    printf("player3:");
    for(int i=0;i<13;i++){
        print_card(player3[i]);
    }
    printf("\n\n");
    printf("player4:");
    for(int i=0;i<13;i++){
        print_card(player4[i]);
    }
    printf("\n\n");
    
    return 0;
}

void shuffle(){
    int *p,*p2;
    srand((unsigned)time(NULL));
    for(int i=0;i<card_number;i++){
        p = cards+i;
        p2 = cards+rand()%52;
        swag(p, p2);
    }
}

void swag(int *p,int *p2){
    int temp;
    temp = *p;
    *p = *p2;
    *p2 = temp;
}

void give_card(){
    int *p1,*p2,*p3,*p4;
    p1 = player1;
    p2 = player2;
    p3 = player3;
    p4 = player4;
    for(int i=0;i<card_number;i++){
        switch ((i+1)%4) {
            case 1:
                *p1 = cards[i];
                p1++;
                break;
            case 2:
                *p2 = cards[i];
                p2++;
                break;
            case 3:
                *p3 = cards[i];
                p3++;
                break;
            case 0:
                *p4 = cards[i];
                p4++;
                break;
                
            default:
                break;
        }
    }
}

void sort_card(){
    int *p[4];
    int a,b;
    p[0] = player1;
    p[1] = player2;
    p[2] = player3;
    p[3] = player4;
    for(int x=0;x<4;x++){
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < i; ++j) {
                if(*(p[x]+j)%13==0){
                    a = 13;
                } else {
                    a =*(p[x]+j)%13;
                }
                if(*(p[x]+i)%13==0){
                    b = 13;
                } else {
                    b =*(p[x]+i)%13;
                }
                if(a > b){
                    swag(p[x]+j, p[x]+i);
                }
                if(a == b){
                    if(*(p[x]+j)/4>*(p[x]+i)/4){
                        swag(p[x]+j, p[x]+i);
                    }
                }
            }
        }
    }
}

void print_card(int card){
    switch ((card-1)/13) {
        case 0:
            printf("%s","♧");
            break;
        case 1:
            printf("%s","♢");
            break;
        case 2:
            printf("%s","♥");
            break;
        case 3:
            printf("%s","♤");
            break;
        default:
            break;
    }
    switch (card%13) {
        case 0:
            printf("%c",'K');
            break;
        case 1:
            printf("%c",'A');
            break;
        case 11:
            printf("%c",'J');
            break;
        case 12:
            printf("%c",'Q');
            break;
        default:
            printf("%d",card%13);
            break;
    }
    printf(" ");
}

