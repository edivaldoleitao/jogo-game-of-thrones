#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void) {
  
  srand(time(NULL));
  int westeros[10][10],jon_vida=100,cersei_vida=100,rei_vida=100;

  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      westeros[i][j]=0;
    }
  }
  int x_jon=0,y_jon=0;

  westeros[x_jon][y_jon]=1;
  westeros[9][9]=9;
  westeros[4][4]=8;
  
  for(int enemy=0;enemy<20;)
  {
    int x_enemy=rand()%10,y_enemy=rand()%10;
    if(westeros[x_enemy][y_enemy]==0)
    {
      westeros[x_enemy][y_enemy]=5;
      enemy++;
    }
  }
  for(int obstaculo=0;obstaculo<10;)
  {
    int x_obstaculo=rand()%10,y_obstaculo=rand()%10;
    if(westeros[x_obstaculo][y_obstaculo]==0)
    {
      westeros[x_obstaculo][y_obstaculo]=4;
      obstaculo++;
    }
  }
  for(int pocao=0;pocao<10;)
  {
    int x_pocao=rand()%10,y_pocao=rand()%10;
    if(westeros[x_pocao][y_pocao]==0)
    {
      westeros[x_pocao][y_pocao]=3;
      pocao++;
    }
  }
   
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      if(westeros[i][j]!=0)
      {
        printf("%i ",westeros[i][j]);
      }
      else
      {
        printf("- ");
      }
    }
    printf("\n");
  }
  printf("\n");
  do
  {
    printf("\n1-jon\n3-pocoes de vida\n4-obstaculos\n5-inimigos\n9-rei da noite\n(a,s,d,w)-fazem a movimentacao\n");
    char move;
    scanf("%c",&move);
    getchar();

    if(move=='a')
    {
      if(y_jon-1>=0)
      {
        if(westeros[x_jon][y_jon-1]==0)
        {
          westeros[x_jon][y_jon-1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon-1;
                   
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon][y_jon-1]==4)
        {
          printf("\nobstaculo!!\n");
        }
        else if(westeros[x_jon][y_jon-1]==5)
        { 
          printf("\njon encontrou um inimigo!!\n");
          jon_vida=jon_vida-1;
          if(jon_vida>0)
          {
            westeros[x_jon][y_jon-1]=1;
            westeros[x_jon][y_jon]=0;
            y_jon=y_jon-1;
            printf("\njon destruiu um inimigo!!\njon vida :%i",jon_vida);
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          }        
          
        }
        else if(westeros[x_jon][y_jon-1]==3)
        {
          jon_vida+=5;
          westeros[x_jon][y_jon-1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon-1;
          printf("\njon encontrou uma pocao!!\nvida de jon : %i",jon_vida);
           
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon][y_jon-1]==8)
        {
          printf("\njon encontrou cersei para negociar\n");
        
          westeros[x_jon][y_jon-1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon-1;
          int tentativas=0,sucesso;
          while(tentativas!=5)
          {
            int proposta=rand()%101;
            if(proposta>60)
            {
              sucesso++;
            } 
            tentativas++;
          }
          if(sucesso>=3)
          {
            printf("\nnegociacao bem sucedida!!!\n");
            jon_vida+=cersei_vida;
             
            for(int i=0;i<10;i++)
            {
              for(int j=0;j<10;j++)
              {
                if(westeros[i][j]!=0)
                {
                  printf("%i ",westeros[i][j]);
                }
                else
                {
                  printf("- ");
                }
              }
              printf("\n");
            }
            printf("\n");
          }
          else
          {
            printf("\nnegociacao falhou!!\n");
            do
            {
              int atk_jon,atk_cersei,chance=0;              
              while(chance!=1&&cersei_vida>0&&jon_vida>0)
              {            
                atk_jon=rand()%101;
                if(atk_jon>=50)
                {
                  cersei_vida=cersei_vida-10;
                  printf("\njon atacou!!! \nvida cersei :%i",cersei_vida);
                }
                else
                {
                  printf("\njon errou!!\nvez da cersei\n");
                  chance=1;
                }
              }
              chance=0;
               while(chance!=1&&jon_vida>0&&cersei_vida>0)
              {            
                atk_cersei=rand()%101;
                if(atk_cersei>=50)
                {
                  jon_vida=jon_vida-10;
                  printf("\ncersei atacou!!\nvida de jon :%i",jon_vida);
                }
                else
                {
                  printf("\ncersei errou!!\nvez de jon\n");
                  chance=1;
                }
              }
              chance=0;

            }while(jon_vida>0&&cersei_vida>0);
            if(jon_vida>0)
            {
              printf("\njon venceu contra cersei!!\n");
               
              for(int i=0;i<10;i++)
              {
                for(int j=0;j<10;j++)
                {
                  if(westeros[i][j]!=0)
                  {
                    printf("%i ",westeros[i][j]);
                  }
                  else
                  {
                    printf("- ");
                  }
                }
                printf("\n");
              }
              printf("\n");
            }
            else
            {
              printf("\njon morreu!!\n");
              break;
            }
          }
        }
        else if(westeros[x_jon][y_jon-1]==9)
        {
          jon_vida+=5;
          westeros[x_jon][y_jon-1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon-1;
          do
          {
            int atk_jon,atk_rei,chance=0;              
            while(chance!=1&&rei_vida>0)
            {            
              atk_jon=rand()%101;
              if(atk_jon>=50)
              {
                rei_vida=rei_vida-10;
                printf("\njon atacou!!! \nvida rei da noite :%i",rei_vida);
              }
              else
              {
                printf("\njon errou!!\nvez do rei da noite\n");
                chance=1;
              }
            }
            chance=0;
            
            while(chance!=1&&jon_vida>0&&rei_vida>0)
            {            
              atk_rei=rand()%101;
              if(atk_rei>=50)
              {
                jon_vida=jon_vida-5;
                rei_vida+=5;
                printf("\no rei da noite atacou!!\nvida de jon :%i\n",jon_vida);
              }
              else
              {
                printf("\no rei da note errou!!\nvez de jon\n");
                chance=1;
              }
            }
            chance=0;

          }while(rei_vida>0&&jon_vida>0);
          if(jon_vida>0)
          {
            printf("\njon venceu contra o rei da noite !!\n");
            break;
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          } 
        }
      }
      else
      {
        printf("\nfora do cenario!!\n");
      }
    
    }
    
    if(move=='d')
    {
      if(y_jon+1<=9)
      {
        if(westeros[x_jon][y_jon+1]==0)
        {
          westeros[x_jon][y_jon+1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon+1;
                   
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon][y_jon+1]==4)
        {
          printf("\nobstaculo!!\n");
        }
        else if(westeros[x_jon][y_jon+1]==5)
        { 
          printf("\njon encontrou um inimigo!!\n");
          jon_vida=jon_vida-1;
          if(jon_vida>0)
          {
            westeros[x_jon][y_jon+1]=1;
            westeros[x_jon][y_jon]=0;
            y_jon=y_jon+1;
            printf("\njon destruiu um inimigo!!\njon vida :%i",jon_vida);
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          }        
          
        }
        else if(westeros[x_jon][y_jon+1]==3)
        {
          jon_vida+=5;
          westeros[x_jon][y_jon+1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon+1;
          printf("\njon encontrou uma pocao!!\nvida de jon : %i\n",jon_vida);
           
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon][y_jon+1]==8)
        {
          westeros[x_jon][y_jon+1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon+1;
                   
          printf("\njon encontrou cersei para negociar\n");
          int tentativas=0,sucesso;
          while(tentativas!=5)
          {
            int proposta=rand()%101;
            if(proposta>60)
            {
              sucesso++;
            } 
          tentativas++;
          }
          if(sucesso>=3)
          {
            printf("\nnegociacao bem sucedida!!!\n");
            jon_vida+=cersei_vida;
             
            for(int i=0;i<10;i++)
            {
              for(int j=0;j<10;j++)
              {
                if(westeros[i][j]!=0)
                {
                  printf("%i ",westeros[i][j]);
                }
                else
                {
                  printf("- ");
                }
              }
              printf("\n");
            }
            printf("\n");
          }
          else
          {
            printf("\nnegociacao falhou!!\n");
            do
            {
              int atk_jon,atk_cersei,chance=0;              
              while(chance!=1&&cersei_vida>0&&jon_vida>0)
              {            
                atk_jon=rand()%101;
                if(atk_jon>=50)
                {
                  cersei_vida=cersei_vida-10;
                  printf("\njon atacou!!! \nvida cersei :%i",cersei_vida);
                }
                else
                {
                  printf("\njon errou!!\nvez da cersei\n");
                  chance=1;
                }
              }
              chance=0;
               while(chance!=1&&jon_vida>0&&cersei_vida>0)
              {            
                atk_cersei=rand()%101;
                if(atk_cersei>=50)
                {
                  jon_vida=jon_vida-10;
                  printf("\ncersei atacou!!\nvida de jon :%i",jon_vida);
                }
                else
                {
                  printf("\ncersei errou!!\nvez de jon\n");
                  chance=1;
                }
              }
              chance=0;

            }while(jon_vida>0&&cersei_vida>0);
            if(jon_vida>0)
            {
              printf("\njon venceu contra cersei!!\n");
               
              for(int i=0;i<10;i++)
              {
                for(int j=0;j<10;j++)
                {
                  if(westeros[i][j]!=0)
                  {
                    printf("%i ",westeros[i][j]);
                  }
                  else
                  {
                    printf("- ");
                  }
                }
                printf("\n");
              }
              printf("\n");
            }
            else
            {
              printf("\njon morreu!!\n");
              break;
            }
          }
        }
        else if(westeros[x_jon][y_jon+1]==9)
        {
          westeros[x_jon][y_jon+1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon+1;
                   
          do
          {
            int atk_jon,atk_rei,chance=0;              
            while(chance!=1&&rei_vida>0>jon_vida>0)
            {            
              atk_jon=rand()%101;
              if(atk_jon>=50)
              {
                rei_vida=rei_vida-10;
                printf("\njon atacou!!! \nvida rei da noite :%i",rei_vida);
              }
              else
              {
                printf("\njon errou!!\nvez do rei da noite\n");
                chance=1;
              }
            }
            chance=0;
            while(chance!=1&&jon_vida>0)
            {            
              atk_rei=rand()%101;
              if(atk_rei>=50)
              {
                jon_vida=jon_vida-5;
                rei_vida+=5;
                printf("\no rei da noite atacou!!\nvida de jon :%i",jon_vida);
              }
              else
              {
                printf("\no rei da note errou!!\nvez de jon\n");
                chance=1;
              }
            }
            chance=0;

          }while(rei_vida>0&&jon_vida>0);
          if(jon_vida>0)
          {
            printf("\njon venceu contra o rei da noite !!\n");
            break;
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          } 
        }
      }
      else
      {
        printf("\nfora do cenario!!\n");
      }
    }
    
    if(move=='s')
    {
      if(x_jon+1<=9)
      {
        if(westeros[x_jon+1][y_jon]==0)
        {
          westeros[x_jon+1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon+1;
                   
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon+1][y_jon]==4)
        {
          printf("\nobstaculo!!\n");
        }
        else if(westeros[x_jon+1][y_jon]==5)
        { 
          printf("\njon encontrou um inimigo!!\n");
          jon_vida=jon_vida-1;
          if(jon_vida>0)
          {
            westeros[x_jon+1][y_jon]=1;
            westeros[x_jon][y_jon]=0;
            x_jon=x_jon+1;
            printf("\njon destruiu um inimigo!!\njon vida :%i",jon_vida);
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          }        
          
        }
        else if(westeros[x_jon+1][y_jon]==3)
        {
          jon_vida+=5;
          westeros[x_jon+1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon+1;
          printf("\njon encontrou uma pocao!!\nvida de jon : %i\n",jon_vida);
           
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon+1][y_jon]==8)
        {
          westeros[x_jon+1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon+1;
                   
          printf("\njon encontrou cersei para negociar\n");
          int tentativas=0,sucesso;
          while(tentativas!=5)
          {
            int proposta=rand()%101;
            if(proposta>60)
            {
              sucesso++;
            } 
            tentativas++;
          }
          if(sucesso>=3)
          {
            printf("\nnegociacao bem sucedida!!!\n");
            jon_vida+=cersei_vida;
             
            for(int i=0;i<10;i++)
            {
              for(int j=0;j<10;j++)
              {
                if(westeros[i][j]!=0)
                {
                  printf("%i ",westeros[i][j]);
                }
                else
                {
                  printf("- ");
                }
              }
              printf("\n");
            }
            printf("\n");
          }
          else
          {
            printf("\nnegociacao falhou!!\n");
            do
            {
              int atk_jon,atk_cersei,chance=0;              
              while(chance!=1&&cersei_vida>0&&jon_vida>0)
              {            
                atk_jon=rand()%101;
                if(atk_jon>=50)
                {
                  cersei_vida=cersei_vida-10;
                  printf("\njon atacou!!! \nvida cersei :%i\n",cersei_vida);
                }
                else
                {
                  printf("\njon errou!!\nvez da cersei\n");
                  chance=1;
                }
              }
              chance=0;
               while(chance!=1&&jon_vida>0&&cersei_vida>0)
              {            
                atk_cersei=rand()%101;
                if(atk_cersei>=50)
                {
                  jon_vida=jon_vida-10;
                  printf("\ncersei atacou!!\nvida de jon :%i",jon_vida);
                }
                else
                {
                  printf("\ncersei errou!!\nvez de jon\n");
                  chance=1;
                }
              }
              chance=0;

            }while(jon_vida>0&&cersei_vida>0);
            if(jon_vida>0)
            {
              printf("\njon venceu contra cersei!!\n");
               
              for(int i=0;i<10;i++)
              {
                for(int j=0;j<10;j++)
                {
                  if(westeros[i][j]!=0)
                  {
                    printf("%i ",westeros[i][j]);
                  }
                  else
                  {
                    printf("- ");
                  }
                }
                printf("\n");
              }
              printf("\n");
            }
            else
            {
              printf("\njon morreu!!\n");
              break;
            }
          }
        }
        else if(westeros[x_jon+1][y_jon]==9)
        {
          westeros[x_jon+1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon+1;
                   
          do
          {
            int atk_jon,atk_rei,chance=0;              
            while(chance!=1&&rei_vida>0&&jon_vida>0)
            {            
              atk_jon=rand()%101;
              if(atk_jon>=50)
              {
                rei_vida=rei_vida-10;
                printf("\njon atacou!!! \nvida rei da noite :%i",rei_vida);
              }
              else
              {
                printf("\njon errou!!\nvez do rei da noite\n");
                chance=1;
              }
            }
            chance=0;
            while(chance!=1&&jon_vida>0&&rei_vida>0)
            {            
              atk_rei=rand()%101;
              if(atk_rei>=50)
              {
                jon_vida=jon_vida-5;
                rei_vida+=5;
                printf("\no rei da noite atacou!!\nvida de jon :%i",jon_vida);
              }
              else
              {
                printf("\no rei da note errou!!\nvez de jon\n");
                chance=1;
              }
            }
            chance=0;

          }while(rei_vida>0&&jon_vida>0);
          if(jon_vida>0)
          {
            printf("\njon venceu contra o rei da noite !!\n");
            break;
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          } 
        }
      }
      else
      {
        printf("\nfora do cenario!!\n");
      }
    }

     if(move=='w')
    {
      if(x_jon-1>=0)
      {
        if(westeros[x_jon-1][y_jon]==0)
        {
          westeros[x_jon-1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon-1;
                   
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon-1][y_jon]==4)
        {
          printf("\nobstaculo!!\n");
        }
        else if(westeros[x_jon-1][y_jon]==5)
        { 
          printf("\njon encontrou um inimigo!!\n");
          jon_vida=jon_vida-1;
          if(jon_vida>0)
          {
            westeros[x_jon+1][y_jon]=1;
            westeros[x_jon][y_jon]=0;
            x_jon=x_jon-1;
            printf("\njon destruiu um inimigo!!\njon vida :%i",jon_vida);
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          }        
          
        }
        else if(westeros[x_jon-1][y_jon]==3)
        {
          jon_vida+=5;
          westeros[x_jon][y_jon+1]=1;
          westeros[x_jon][y_jon]=0;
          y_jon=y_jon-1;
          printf("\njon encontrou uma pocao!!\nvida de jon : %i\n",jon_vida);
           
          for(int i=0;i<10;i++)
          {
            for(int j=0;j<10;j++)
            {
              if(westeros[i][j]!=0)
              {
                printf("%i ",westeros[i][j]);
              }
              else
              {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("\n");
        }
        else if(westeros[x_jon-1][y_jon]==8)
        {
          westeros[x_jon-1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon-1;
                   
          printf("\njon encontrou cersei para negociar\n");
          int tentativas=0,sucesso;
          while(tentativas!=5)
          {
            int proposta=rand()%101;
            if(proposta>60)
            {
              sucesso++;
            } 
            tentativas++;
          }
          if(sucesso>=3)
          {
            printf("\nnegociacao bem sucedida!!!\n");
            jon_vida+=cersei_vida;
             
            for(int i=0;i<10;i++)
            {
              for(int j=0;j<10;j++)
              {
                if(westeros[i][j]!=0)
                {
                  printf("%i ",westeros[i][j]);
                }
                else
                {
                  printf("- ");
                }
              }
              printf("\n");
            }
            printf("\n");
          }
          else
          {
            printf("\nnegociacao falhou!!\n");
            do
            {
              int atk_jon,atk_cersei,chance=0;              
              while(chance!=1&&cersei_vida>0&&jon_vida>0)
              {            
                atk_jon=rand()%101;
                if(atk_jon>=50)
                {
                  cersei_vida=cersei_vida-10;
                  printf("\njon atacou!!! \nvida cersei :%i",cersei_vida);
                }
                else
                {
                  printf("\njon errou!!\nvez da cersei\n");
                  chance=1;
                }
              }
              chance=0;
               while(chance!=1&&jon_vida>0)
              {            
                atk_cersei=rand()%101;
                if(atk_cersei>=50)
                {
                  jon_vida=jon_vida-10;
                  printf("\ncersei atacou!!\nvida de jon :%i",jon_vida);
                }
                else
                {
                  printf("\ncersei errou!!\nvez de jon\n");
                  chance=1;
                }
              }
              chance=0;

            }while(jon_vida>0&&cersei_vida>0);
            if(jon_vida>0)
            {
              printf("\njon venceu contra cersei!!\n");
               
              for(int i=0;i<10;i++)
              {
                for(int j=0;j<10;j++)
                {
                  if(westeros[i][j]!=0)
                  {
                    printf("%i ",westeros[i][j]);
                  }
                  else
                  {
                    printf("- ");
                  }
                }
                printf("\n");
              }
              printf("\n");
            }
            else
            {
              printf("\njon morreu!!\n");
              break;
            }
          }
        }
        else if(westeros[x_jon+1][y_jon]==9)
        {
          westeros[x_jon-1][y_jon]=1;
          westeros[x_jon][y_jon]=0;
          x_jon=x_jon-1;
                   
          do
          {
            int atk_jon,atk_rei,chance=0;              
            while(chance!=1&&rei_vida>0&&rei_vida>0)
            {            
              atk_jon=rand()%101;
              if(atk_jon>=50)
              {
                rei_vida=rei_vida-10;
                printf("\njon atacou!!! \nvida rei da noite :%i",rei_vida);
              }
              else
              {
                printf("\njon errou!!\nvez do rei da noite\n");
                chance=1;
              }
            }
            chance=0;
            while(chance!=1&&jon_vida>0&&rei_vida>0)
            {            
              atk_rei=rand()%101;
              if(atk_rei>=50)
              {
                jon_vida=jon_vida-5;
                rei_vida+=5;
                printf("\no rei da noite atacou!!\nvida de jon :%i",jon_vida);
              }
              else
              {
                printf("\no rei da note errou!!\nvez de jon\n");
                chance=1;
              }
            }
            chance=0;

          }while(rei_vida>0&&jon_vida>0);
          if(jon_vida>0)
          {
            printf("\njon venceu contra o rei da noite !!\n");
            break;
          }
          else
          {
            printf("\njon morreu!!\n");
            break;
          } 
        }
      }
      else
      {
        printf("\nfora do cenario!!\n");
      }
    }


  }
  while(jon_vida>0);
  

  return 0;
}
