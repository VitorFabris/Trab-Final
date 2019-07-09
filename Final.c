#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define WIDTH 640
#define HEIGHT 480
#define SIZEARR 10

//char *Nome();
// set all the things that we ill use NULL, seems like a good idea
ALLEGRO_DISPLAY *display  = NULL;
ALLEGRO_EVENT_QUEUE *fila = NULL;
ALLEGRO_BITMAP *porta1    = NULL,*sprite1 = NULL,*sprite2 = NULL,*sprite3 = NULL,*sprite4 = NULL,*sprite5 = NULL,*sprite6 = NULL,*spriteport = NULL,*porta2 = NULL,*porta3 = NULL,*btEnter = NULL,*btChar0=NULL,*btChar1=NULL,*btChar2=NULL,*btChar3=NULL,*btChar4=NULL,*btChar5=NULL;
ALLEGRO_BITMAP *fall1 = NULL,*fall2 = NULL,*fall3 = NULL,*fall4 = NULL,*fall5 = NULL,*fall6 = NULL,*newspr = NULL,*textbox = NULL;
ALLEGRO_BITMAP *dance1 = NULL,*dance2 = NULL,*dance3 = NULL,*dance4 = NULL,*dance5 = NULL,*dance6 = NULL;
ALLEGRO_FONT *font        = NULL,*font2  = NULL;
ALLEGRO_TIMER *timer      = NULL;
 
 // just creating an error msg 
void error_msg(char *text){
	al_show_native_message_box(display,"ERRO",
		"There is a brutal error, descripted by:",
		text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
}
 
 //this f*ckn sh*t its just to see if there is some error while initializing anything, we set all NULL of course 
int iniciar(){
    if (!al_init()){
        error_msg("Error in Allegro initializating");
        return 0;
    }
    
    if(!al_init_primitives_addon()){
        error_msg("Error in drawing initializating");
        return 0;                          
    } 

    if (!al_install_keyboard()){
        error_msg("Error in Keyboard initializating");
        return 0;
    }
    
    timer = al_create_timer(1.0 / 60.0);
    if(!timer) {
        error_msg("Error in timer creating");
        return 0;
    }
    
    display = al_create_display(1080, 640);
    if (!display){
        error_msg("Error in display creating");
        return 0;
    }  
    //this is to change my title
    al_set_window_title(display, "Jogson bb");
    
    fila = al_create_event_queue();
    if (!fila){
        error_msg("Error in the event queue");
        al_destroy_display(display);
        return 0;
    }
    
    //new things now for mouse
    if (!al_install_mouse()){
        error_msg("Error in mouse installing");
        al_destroy_display(display);
        return 0;
    }
    if (!al_set_system_mouse_cursor(display,ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        error_msg("Error in mouse setting");
        al_destroy_display(display);
        return 0;
    }  
    
    al_init_image_addon();
    if(!al_init_image_addon()){
        error_msg("Error in image initializating");
        return 0;                          
    }
    
    fall1 = al_load_bitmap("hstFall1.bmp");
     if (!fall1){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    fall2 = al_load_bitmap("hstFall2.bmp");
     if (!fall2){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    fall3 = al_load_bitmap("hstFall3.bmp");
     if (!fall3){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    fall4 = al_load_bitmap("hstFall4.bmp");
     if (!fall4){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    fall5 = al_load_bitmap("hstFall5.bmp");
     if (!fall5){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    fall6 = al_load_bitmap("hstFall6.bmp");
     if (!fall6){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    
    dance1 = al_load_bitmap("dance1.bmp");
     if (!dance1){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    dance2 = al_load_bitmap("dance2.bmp");
     if (!dance2){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    dance3 = al_load_bitmap("dance3.bmp");
     if (!dance3){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    dance4 = al_load_bitmap("dance4.bmp");
     if (!dance4){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    dance5 = al_load_bitmap("dance5.bmp");
     if (!dance5){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    dance6 = al_load_bitmap("dance6.bmp");
     if (!dance6){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    
    
    sprite1 = al_load_bitmap("front1.bmp");
     if (!sprite1){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    sprite2 = al_load_bitmap("front2.bmp");
     if (!sprite2){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    sprite3 = al_load_bitmap("front3.bmp");
     if (!sprite3){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    sprite4 = al_load_bitmap("front4.bmp");
     if (!sprite4){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    sprite5 = al_load_bitmap("front5.bmp");
     if (!sprite5){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    sprite6 = al_load_bitmap("front6.bmp");
     if (!sprite6){
        error_msg("Error in image loading");
        al_destroy_display(display);
        return 0;
    }
    spriteport = al_create_bitmap(680,64);
     if (!spriteport){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     newspr = al_create_bitmap(64,64);
     if (!newspr){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     textbox = al_create_bitmap(650,500);
     if (!textbox){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     btChar0 = al_load_bitmap("selec1.bmp");
     btChar1 =al_load_bitmap("selec2.bmp");
     btChar2 = al_load_bitmap("selec3.bmp");
     btChar3 = al_load_bitmap("selec4.bmp");
     btChar4 =al_load_bitmap("selec5.bmp");
     btChar5 = al_load_bitmap("selec6.bmp");
     if (!btChar0||!btChar1||!btChar2||!btChar3||!btChar4||!btChar5){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
    
    //criando um cubo em bitmap para cada quadrado do jogo
     porta1 = al_create_bitmap(200,500);
     if (!porta1){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     
     porta2 = al_create_bitmap(200,500);
     if (!porta2){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     
     porta3 = al_create_bitmap(200,500);
     if (!porta3){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     
     btEnter = al_create_bitmap(400,30);
     if (!btEnter){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
     
    al_init_font_addon();
    if(!al_init_ttf_addon()){
        error_msg("Error in font initializating");
        return 0;                          
    }
    
    font = al_load_font("fast99.ttf",32,0);
    if (!font){
        error_msg("Error in font loading");
        al_destroy_display(display);
        return -1;
    }
    
    font2 = al_load_font("arial.ttf",24,0);
    if (!font2){
        error_msg("Error in font loading");
        al_destroy_display(display);
        return -1;
    }
    
    //there is a event register, in this case of the keyboard and display
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_register_event_source(fila, al_get_mouse_event_source()); 
    al_register_event_source(fila, al_get_display_event_source(display));
    al_register_event_source(fila, al_get_timer_event_source(timer));
    
    al_start_timer(timer);
    
    return 1;
}

    void portas(){
       al_set_target_bitmap(porta1);
       al_clear_to_color(al_map_rgb(255,255,255));
       al_set_target_bitmap(porta2);
       al_clear_to_color(al_map_rgb(255,255,255));
       al_set_target_bitmap(porta3);
       al_clear_to_color(al_map_rgb(255,255,255));
       al_set_target_bitmap(al_get_backbuffer(display));
       al_draw_bitmap(porta1,140,100,0);
       al_draw_bitmap(porta2,440,100,0);
       al_draw_bitmap(porta3,740,100,0);
       al_flip_display();
    }
    
    void p(int a, int b, int c){
         al_set_target_bitmap(porta1);
         al_clear_to_color(al_map_rgb(a,b,c));
         al_draw_text(font,al_map_rgb(255,255,255),100, 250, ALLEGRO_ALIGN_CENTRE, "1");
         al_set_target_bitmap(al_get_backbuffer(display));
         al_draw_bitmap(porta1,140,100,0);
         al_flip_display();
    }
    void pp(int a, int b, int c){
        al_set_target_bitmap(porta2);
        al_clear_to_color(al_map_rgb(a,b,c));
        al_draw_text(font,al_map_rgb(255,255,255),100, 250, ALLEGRO_ALIGN_CENTRE, "2");
        al_set_target_bitmap(al_get_backbuffer(display));
        al_draw_bitmap(porta2,440,100,0);
        al_flip_display();
    }
    void ppp(int a, int b, int c){
       al_set_target_bitmap(porta3);
       al_clear_to_color(al_map_rgb(a,b,c));
       al_draw_text(font,al_map_rgb(255,255,255),100, 250, ALLEGRO_ALIGN_CENTRE, "3");
       al_set_target_bitmap(al_get_backbuffer(display));
       al_draw_bitmap(porta3,740,100,0);
       al_flip_display();
    }
    
    struct quest{
           char q[1000];
    };
    
    typedef struct quest qu;
    void menu();
    void lvl();
    void destroir();
    
    qu *question(){
         int i;
         qu *v;
         FILE *f;
         v=(qu*) malloc(50*sizeof(qu));
         f = fopen("questions.txt","r");
         for(i=0;i<50;i++){
            fgets(v[i].q, 1000, f);
            v[i].q[strlen(v[i].q)-1]='\0';
            
         }
         fclose(f);
         return v;
    
    }
    
    int *answer(){
         int i;
         int *v;
         FILE *f;
         v=(int*) malloc(50*sizeof(int));
         f = fopen("answers.txt","r");
         for(i=0;i<50;i++){
            fscanf(f,"%d",&v[i]);
            
         }
         fclose(f);
         return v;
    
    }
    
    void makeAquestion(qu *v,int *vn,int *l,int fase){
         srand(time(NULL));
         int ex=0;
         do{
         printf("here\n");
         *l=rand()%50;
         if(!vn[*l])
               ex=1;
         }while(!ex);
         printf("exit\n");
         printf("%s",v[*l].q);
         if(fase==6||fase==14||fase==22||fase==30)
         al_draw_text(font2,al_map_rgb(0,255,0),540,20, ALLEGRO_ALIGN_CENTRE, "Vai na Sorte");
         else
         al_draw_textf(font2,al_map_rgb(0,255,0),540,20, ALLEGRO_ALIGN_CENTRE, "Fase %d: %s",fase+1,v[*l].q);
         al_flip_display();
         vn[*l]=1;
         
         
    }
    
    int testYourbrain(int fases){
         srand(time(NULL));
         int l;
         int ex=0;
         printf("here 2\n");
         l=1 + rand()%fases-1;
         if(fases==6||fases==14||fases==22||fases==30)
         al_draw_text(font2,al_map_rgb(0,255,0),540,20, ALLEGRO_ALIGN_CENTRE, "Vai na Sorte");
         else
         al_draw_textf(font2,al_map_rgb(0,255,0),540,20, ALLEGRO_ALIGN_CENTRE, "Level %d: What was the level %d answer?",fases+1,l+1);
         al_flip_display();
         return l;
    }
    
    void start(){
         al_clear_to_color(al_map_rgb(0,0,0));
         portas(); 
    }
    
    void destroir();
    
    char *Nome(){
               al_clear_to_color(al_map_rgb(0,255,0));
               
               al_flip_display();
               char *a;
               a=(char*) malloc(10*sizeof(char));
               int i=0,EndName=0,donterase=0;
               while(!EndName){   
                   al_draw_text(font,al_map_rgb(255,255,255),540,100, ALLEGRO_ALIGN_CENTRE, "Digite seu Nome:");
                   al_draw_text(font2,al_map_rgb(255,255,255),540,140, ALLEGRO_ALIGN_CENTRE, "Utilize Backspace para apagar algo e Enter para enviar");
                   al_draw_text(font2,al_map_rgb(255,255,255),540,160, ALLEGRO_ALIGN_CENTRE, "No maximo 10 letras.");
                   al_flip_display();
                   ALLEGRO_EVENT sta;
                   al_wait_for_event(fila,&sta);
                   if(sta.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                       destroir();
                   }     
                   if(sta.type==ALLEGRO_EVENT_KEY_DOWN){
                       
                           if(sta.keyboard.keycode==ALLEGRO_KEY_A)
                               a[i]='A';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_B)
                               a[i]='B';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_C)
                               a[i]='C';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_D)
                               a[i]='D';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_E)
                               a[i]='E';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_F)
                               a[i]='F';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_G)
                               a[i]='G';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_H)
                               a[i]='H';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_I)
                               a[i]='I';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_J)
                               a[i]='J';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_K)
                               a[i]='K';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_L)
                               a[i]='L';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_M)
                               a[i]='M';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_N)
                               a[i]='N';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_O)
                               a[i]='O';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_P)
                               a[i]='P';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_Q)
                               a[i]='Q';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_R)
                               a[i]='R';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_S)
                               a[i]='S';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_T)
                               a[i]='T';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_U)
                               a[i]='U';
                           
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_V)
                               a[i]='V';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_W)
                               a[i]='W';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_X)
                               a[i]='X';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_Y)
                               a[i]='Y';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_Z)
                               a[i]='Z';
                               
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_ENTER)
                               EndName=1;
                           else if(sta.keyboard.keycode==ALLEGRO_KEY_BACKSPACE){
                                   donterase=1;
                                   i-=1;
                                   a[i]='\0';
                                   i-=1;
                           }
                           else 
                           i-=1;
                               
                           if(!EndName){
                               int j,pos=540,inc=0;
                               al_clear_to_color(al_map_rgb(0,255,0));
                                   
                                       for(j=i;j>=0;j--){
                                           al_draw_textf(font,al_map_rgb(255,255,255),pos+inc, 300, ALLEGRO_ALIGN_CENTRE,"%c", a[j]);
                                           inc-=25;
                                           al_flip_display();
                                       }
                                       inc=0;
                                   
                           }
                       
                       donterase=0;
                       i++;
                       if(i==11)
                       EndName=1;
                       
                   }
                   
               }
               a[i-1]='\0';
               a =(char*) realloc(a, i*sizeof(char));
               
               return a;
          
          }
    
    
    void menu(char *nome){
         int ex=0,tem=0;
         al_clear_to_color(al_map_rgb(0,255,0));
         al_draw_textf(font,al_map_rgb(255,255,255),540, 50, ALLEGRO_ALIGN_CENTRE,"Bem Vindo: %s", nome);
         al_draw_text(font,al_map_rgb(255,255,255),540,400, ALLEGRO_ALIGN_CENTRE, "PRESS ENTER TO PLAY");
         al_flip_display();
         while(!ex){
                    ALLEGRO_EVENT sta;
                    al_wait_for_event(fila,&sta);
                   if(sta.type==ALLEGRO_EVENT_TIMER){
                     tem += 1; 
                     //printf("%d",tem);
                   }
                   if(sta.type==ALLEGRO_EVENT_KEY_DOWN){
                           if(sta.keyboard.keycode==ALLEGRO_KEY_ENTER){
                                ex = 1;
                           }
                   }
                   if(sta.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                       destroir();
                   }  
                   
                   if(tem==70){
                       al_set_target_bitmap(btEnter);
                       al_clear_to_color(al_map_rgb(0,255,0));
                       al_set_target_bitmap(al_get_backbuffer(display));
                       al_draw_bitmap(btEnter,340,400,0);
                       al_flip_display();
                       tem *=-1;
                   }
                   if(tem==0){
                       al_set_target_bitmap(btEnter);
                       al_draw_text(font,al_map_rgb(255,255,255),200,0, ALLEGRO_ALIGN_CENTRE, "PRESS ENTER TO PLAY");
                       al_set_target_bitmap(al_get_backbuffer(display));
                       al_draw_bitmap(btEnter,340,400,0);
                       al_flip_display();
                   }
                  
         }
     }

     void Actualanswer(int *n){
          int i,w=140,ans=0,ativo=0;
          printf("\nentro na resposta\n");
          
          while(!ans){
                 ativo=0;
                 
                 while (!al_is_event_queue_empty(fila)){
                     ALLEGRO_EVENT evento;
                     al_wait_for_event(fila,&evento); 
                   if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                               //printf("ta reconhecendo a porta\n");
                               w=140;
                       if(evento.mouse.x>=w&&evento.mouse.x<=w+200&&evento.mouse.y>=100&&evento.mouse.y<=600){
                       ativo=1;
                       }
                       else if(evento.mouse.x>=w+300&&evento.mouse.x<=w+500&&evento.mouse.y>=100&&evento.mouse.y<=600){
                       ativo=2;
                       }
                       else if(evento.mouse.x>=w+600&&evento.mouse.x<=w+800&&evento.mouse.y>=100&&evento.mouse.y<=600){
                       ativo=3;
                       }
                       else
                       ativo=0;
                       
                   } 
                   if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                        w=140;
                       if(evento.mouse.x>=w&&evento.mouse.x<=w+200&&evento.mouse.y>=100&&evento.mouse.y<=600){
                                    *n=1;
                                    ans++;
                       }
                       w+=300; 
                       if(evento.mouse.x>=w&&evento.mouse.x<=w+200&&evento.mouse.y>=100&&evento.mouse.y<=600){
                                    *n=2;
                                    ans++;
                       }
                       w+=300; 
                       if(evento.mouse.x>=w&&evento.mouse.x<=w+200&&evento.mouse.y>=100&&evento.mouse.y<=600){
                                    *n=3;
                                    ans++;
                       }
                   }
                }
               
               if(ativo==1)
                p(255,0,0);
               else if(ativo==2)
               pp(255,0,0);
               else if(ativo==3)
               ppp(255,0,0);
               else if(!ativo){
                    p(255,255,255);
                    pp(255,255,255);
                    ppp(255,255,255);
               }
               
               
              
          }
     
     }

     void lvl(qu *vet,int *vetnum,int *resp,int *perg,int fase,int *rsp,int p){
            int fasee;
            srand(time(NULL));
            if(fase<15)
            fasee=rand()%3;
            else if(fase>=15&&fase<=35)
            fasee=rand()%2;
            else
            fasee=rand()%1;
            start();
            al_draw_textf(font2,al_map_rgb(255,255,255),900,20, ALLEGRO_ALIGN_CENTRE, "Pontos: %d",p);
            al_flip_display();
            if(fasee==1&&fase>3){
                        *rsp=1;
                        *perg=testYourbrain(fase);
            }
            else{
                 makeAquestion(vet,vetnum,perg,fase);
                 *rsp=0;
            }
            printf("\nja fez a questao\n");
            Actualanswer(resp);
     }

     void Lost(int *resp, int *perg, int *ex,int *i,char *nome){
         int exit=0,j;
         al_clear_to_color(al_map_rgb(0,0,0));
         al_draw_text(font,al_map_rgb(255,255,255),540, 50, ALLEGRO_ALIGN_CENTRE, nome);
         al_draw_text(font,al_map_rgb(255,255,255),540,100, ALLEGRO_ALIGN_CENTRE, "PO IRMAO PERDEU!");
         al_draw_text(font,al_map_rgb(255,255,255),540,150, ALLEGRO_ALIGN_CENTRE, "VAI FAZER O RANKING!");
         al_draw_text(font,al_map_rgb(255,255,255),540,500, ALLEGRO_ALIGN_CENTRE, "PRESS ENTER TO QUIT");
         al_draw_text(font,al_map_rgb(255,255,255),540,400, ALLEGRO_ALIGN_CENTRE, "PRESS R TO PLAY AGAIN");
         al_flip_display();
         while(!exit){
               ALLEGRO_EVENT sta;
               al_wait_for_event(fila,&sta);        
               if(sta.type==ALLEGRO_EVENT_KEY_DOWN){
                   if(sta.keyboard.keycode==ALLEGRO_KEY_ENTER){
                        *ex=1;
                        exit=1;
                   }
                   if(sta.keyboard.keycode==ALLEGRO_KEY_R){
                       
                       *ex=0;
                       *i=0;
                       for(j=0;j<50;j++){
                                         *(resp+j)=0;
                                         *(perg+j)=0;
                       }
                                         
                       menu(nome);
                       printf("saiu");
                       exit=1;
                       
                       
                   }
               }
               if(sta.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                   destroir();
               }       
         }
         printf("\nTem q sair daqui\n");
     
     }

     void destroir(){
         al_destroy_display(display);
         al_destroy_event_queue(fila);
         al_destroy_bitmap(porta1);
         al_destroy_bitmap(porta2);
         al_destroy_bitmap(porta3);
         al_destroy_bitmap(sprite1);
         al_destroy_bitmap(sprite2);
         al_destroy_bitmap(sprite3);
         al_destroy_bitmap(sprite4);
         al_destroy_bitmap(sprite5);
         al_destroy_bitmap(sprite6);
         al_destroy_bitmap(btChar0);
         al_destroy_bitmap(btChar1);
         al_destroy_bitmap(btChar2);
         al_destroy_bitmap(btChar3);
         al_destroy_bitmap(btChar4);
         al_destroy_bitmap(btChar5);
         al_destroy_bitmap(spriteport);
         al_destroy_font(font);
         al_destroy_font(font2);
     }
     
     void animarlixo(int *champs){
          int altura=64,largura=64;
          int colunas=9, catu=0;
          int regiaox=0,regiaoy=0;
          int frames=5, frameatu=0;
          int loop=0,desenha=0;
          al_convert_mask_to_alpha(sprite1,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(sprite2,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(sprite3,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(btChar0,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(btChar1,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(btChar2,al_map_rgb(255,255,255));
          al_clear_to_color(al_map_rgb(0,255,0));
          al_draw_text(font,al_map_rgb(255,255,255),540,50, ALLEGRO_ALIGN_CENTRE, "CHOOSE YOUR CHAMPION:");
          al_flip_display();
          int i,w=200;
          bool champ[3];
          
          while(!loop){
              ALLEGRO_EVENT evento;
              al_wait_for_event(fila,&evento);
              
              for(i=0;i<3;i++){
                champ[i]=(evento.mouse.x>=w&&evento.mouse.x<=w+64&&evento.mouse.y>=100&&evento.mouse.y<=600);
                w+=308; 
              }
              w=200;
              if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                   destroir();
               } 
              if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(champ[0]){
                    *champs=1;
                    al_set_target_bitmap(spriteport);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(spriteport,200,250,0);
                    al_draw_bitmap(btChar0,500,250,0);
                } 
                if(champ[1]){
                    *champs=2;
                    al_set_target_bitmap(spriteport);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(spriteport,200,250,0);
                    al_draw_bitmap(btChar1,500,250,0);
                }  
                if(champ[2]){
                    *champs=3;
                    al_set_target_bitmap(spriteport);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(spriteport,200,250,0);
                    al_draw_bitmap(btChar2,500,250,0);
                }   
                loop=1;
              al_flip_display();
              }
              
              else if(evento.type==ALLEGRO_EVENT_TIMER){
              
                  frameatu++;
                  if(frameatu >= frames){
                      frameatu=0;
                      catu++;
                      if(catu>= colunas){
                      catu=0;
                      }
                      regiaox=catu*largura;
                  }
                  desenha=1;
              }
              if(desenha){
                  al_set_target_bitmap(spriteport);
                  al_clear_to_color(al_map_rgb(0,255,0));
                  al_draw_bitmap_region(sprite1,regiaox,regiaoy,largura,altura,0,0,0);
                  al_draw_bitmap_region(sprite2,regiaox,regiaoy,largura,altura,308,0,0);
                  al_draw_bitmap_region(sprite3,regiaox,regiaoy,largura,altura,616,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(spriteport,200,250,0);
              }
              
              al_flip_display();
              desenha=0;
                       
          }
          
          
          
     }
     
     void animardeVDD(int *champs){
          int altura=64,largura=64;
          int colunas=9, catu=0;
          int regiaox=0,regiaoy=0;
          int frames=5, frameatu=0;
          int loop=0,desenha=0;
          al_convert_mask_to_alpha(sprite4,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(sprite5,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(sprite6,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(btChar3,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(btChar4,al_map_rgb(255,255,255));
          al_convert_mask_to_alpha(btChar5,al_map_rgb(255,255,255));
          al_clear_to_color(al_map_rgb(0,255,0));
          al_draw_text(font,al_map_rgb(255,255,255),540,50, ALLEGRO_ALIGN_CENTRE, "CHOOSE YOUR CHAMPION:");
          al_flip_display();
          int i,w=200;
          bool champ[3];
          
          while(!loop){
              ALLEGRO_EVENT evento;
              al_wait_for_event(fila,&evento);
              
              for(i=0;i<3;i++){
                champ[i]=(evento.mouse.x>=w&&evento.mouse.x<=w+64&&evento.mouse.y>=100&&evento.mouse.y<=600);
                w+=308; 
              }
              w=200;
            
              if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                   destroir();
               } 
              if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(champ[0]){
                    *champs=4;
                    al_set_target_bitmap(spriteport);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(spriteport,200,250,0);
                    al_draw_bitmap(btChar3,500,250,0);
                } 
                if(champ[1]){
                    *champs=5;
                    al_set_target_bitmap(spriteport);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(spriteport,200,250,0);
                    al_draw_bitmap(btChar4,500,250,0);
                }  
                if(champ[2]){
                    *champs=6;
                    al_set_target_bitmap(spriteport);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(spriteport,200,250,0);
                    al_draw_bitmap(btChar5,500,250,0);
                }   
                loop=1;
              al_flip_display();
              }
              
              else if(evento.type==ALLEGRO_EVENT_TIMER){
              
                  frameatu++;
                  if(frameatu >= frames){
                      frameatu=0;
                      catu++;
                      if(catu>= colunas){
                      catu=0;
                      }
                      regiaox=catu*largura;
                  }
                  desenha=1;
              }
              if(desenha){
                  al_set_target_bitmap(spriteport);
                  al_clear_to_color(al_map_rgb(0,255,0));
                  al_draw_bitmap_region(sprite4,regiaox,regiaoy,largura,altura,0,0,0);
                  al_draw_bitmap_region(sprite5,regiaox,regiaoy,largura,altura,308,0,0);
                  al_draw_bitmap_region(sprite6,regiaox,regiaoy,largura,altura,616,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(spriteport,200,250,0);
              }
              
              al_flip_display();
              desenha=0;
                       
          }
          
          
          
     }
     
     void Male_Female(int *M_F,char *nome){
         al_clear_to_color(al_map_rgb(0,255,0));
         al_draw_text(font,al_map_rgb(255,255,255),540, 50, ALLEGRO_ALIGN_CENTRE, nome);
         al_draw_text(font,al_map_rgb(255,255,255),540,100, ALLEGRO_ALIGN_CENTRE, "ARE YOU?");
         al_draw_text(font,al_map_rgb(255,255,255),540,250, ALLEGRO_ALIGN_CENTRE, "PRESS M TO MALE");
         al_draw_text(font,al_map_rgb(255,255,255),540,450, ALLEGRO_ALIGN_CENTRE, "PRES F TO FEMALE");
         al_flip_display();
         int decidido=0;
         while(!decidido){
              ALLEGRO_EVENT evento;
              al_wait_for_event(fila,&evento);
              
              if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                   destroir();
              } 
              if(evento.type==ALLEGRO_EVENT_KEY_DOWN){
                           if(evento.keyboard.keycode==ALLEGRO_KEY_M){
                                *M_F=1;
                                decidido++;
                           }
                           if(evento.keyboard.keycode==ALLEGRO_KEY_F){
                                *M_F=0;
                                decidido++;
                           }
              }
                       
                
        }
            
    }
    
    
    
    void History(int choichoi){
        
        int ex=0;
        al_clear_to_color(al_map_rgb(0,255,0));
        ALLEGRO_BITMAP *a,*danc,*coming;
        
        if(choichoi==1){
            a= fall1;   
            danc=dance1;
            coming=sprite1;
        }
        if(choichoi==2){
            a= fall2;   
            danc=dance2;
            coming=sprite2;
        }
        if(choichoi==3){
            a= fall3;   
            danc=dance3;
            coming=sprite3;
        }
        if(choichoi==4){
            a= fall4;   
            danc=dance4;
            coming=sprite4;
        }
        if(choichoi==5){
            a= fall5;   
            danc=dance5;
            coming=sprite5;
        }
        if(choichoi==6){
            a= fall6;   
            danc=dance6;
            coming=sprite6;
        }
        al_convert_mask_to_alpha(a,al_map_rgb(255,255,255));
        al_convert_mask_to_alpha(danc,al_map_rgb(255,255,255));
        int altura=64,largura=64;
          int colunas=9, catu=0;
          int regiaox=0,regiaoy=0;
          int frames=10, frameatu=0;
          
          int desenha=0;
          int txt=0;
          
          int chegano=0;
          int posy=-250;
          
          while(!chegano){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila,&evento);
            if(evento.type==ALLEGRO_EVENT_TIMER){
              
                  frameatu++;
                  if(frameatu >= frames){
                      frameatu=0;
                      catu++;
                      if(catu>= colunas){
                      catu=0;
                      }
                      regiaox=catu*largura;
                    posy+=6;  
                  }
                  
                  desenha=1;
              }
              if(desenha){
                  al_set_target_bitmap(newspr);
                  al_clear_to_color(al_map_rgb(0,255,0));
                  al_draw_bitmap_region(coming,regiaox,regiaoy,largura,altura,0,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(newspr,100,posy,0);
              }
              al_flip_display(); 
              if(posy>=300)
              chegano=1;   
            
            }
          colunas=7;
        frames=10;
        frameatu=0;
        catu=0;
        while(!ex){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila,&evento);
            
            
            if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                   destroir();
              } 
            if(evento.type==ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode==ALLEGRO_KEY_ENTER){
                    txt++;
                }
            }
            if(evento.type==ALLEGRO_EVENT_TIMER){
              
                  frameatu++;
                  if(frameatu >= frames){
                      frameatu=0;
                      catu++;
                      if(catu>= colunas){
                      catu=0;
                      }
                      regiaox=catu*largura;
                  }
                  desenha=1;
              }
              if(desenha){
                  al_set_target_bitmap(newspr);
                  al_clear_to_color(al_map_rgb(0,255,0));
                  al_draw_bitmap_region(danc,regiaox,regiaoy,largura,altura,0,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(newspr,100,300,0);
              }
              if(!txt){
                al_set_target_bitmap(textbox);
                al_clear_to_color(al_map_rgb(0,255,0));
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Ola, eu sou ...");
                al_draw_text(font2,al_map_rgb(255,255,255),250,30, ALLEGRO_ALIGN_CENTRE, "Espera eu sou voce na verdade, pode");
                al_draw_text(font2,al_map_rgb(255,255,255),250,50, ALLEGRO_ALIGN_CENTRE, "parecer um pouco estranho, mas seja");
                al_draw_text(font2,al_map_rgb(255,255,255),250,70, ALLEGRO_ALIGN_CENTRE, "bem vindo ao Tres portas, acalmesse" );
                al_draw_text(font2,al_map_rgb(255,255,255),250,90, ALLEGRO_ALIGN_CENTRE, "eu irei 'me' contar nossa  historia...");
                al_draw_text(font2,al_map_rgb(255,255,255),350,400, ALLEGRO_ALIGN_CENTRE, "Press Enter to continue");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(textbox,400,100,0);
              }
              if(txt==1){
                al_set_target_bitmap(textbox);
                al_clear_to_color(al_map_rgb(0,255,0));
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Bom, como voce deve saber, ou melhor eu,");
                al_draw_text(font2,al_map_rgb(255,255,255),250,30, ALLEGRO_ALIGN_CENTRE, "sempre fomos muito amigaveis  com  todos");
                al_draw_text(font2,al_map_rgb(255,255,255),250,50, ALLEGRO_ALIGN_CENTRE, "adoravamos caminhar de noite como todos,");
                al_draw_text(font2,al_map_rgb(255,255,255),250,70, ALLEGRO_ALIGN_CENTRE, "mas em um certo dia algo muito  estranho");
                al_draw_text(font2,al_map_rgb(255,255,255),250,90, ALLEGRO_ALIGN_CENTRE, "aconteceu...");
                al_draw_text(font2,al_map_rgb(255,255,255),350,400, ALLEGRO_ALIGN_CENTRE, "Press Enter to continue");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(textbox,400,100,0);
              }
              if(txt==2){
                al_set_target_bitmap(textbox);
                al_clear_to_color(al_map_rgb(0,255,0));
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Infelizmente nao nos lembramos de  tudo, mas");
                al_draw_text(font2,al_map_rgb(255,255,255),250,30, ALLEGRO_ALIGN_CENTRE, "eu acredito que talvez possamos descobrir,");
                al_draw_text(font2,al_map_rgb(255,255,255),250,50, ALLEGRO_ALIGN_CENTRE, "preciso de sua ajuda, ou no caso  da minha");
                al_draw_text(font2,al_map_rgb(255,255,255),250,70, ALLEGRO_ALIGN_CENTRE, "para descobrir quem nos trancou aqui...");
                al_draw_text(font2,al_map_rgb(255,255,255),350,400, ALLEGRO_ALIGN_CENTRE, "Press Enter to continue");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(textbox,400,100,0);
              }
              if(txt==3){
                al_set_target_bitmap(textbox);
                al_clear_to_color(al_map_rgb(0,255,0));
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Nao vai ser uma tarefa  facil,  mas  acredito");
                al_draw_text(font2,al_map_rgb(255,255,255),250,35, ALLEGRO_ALIGN_CENTRE, "que conseguiremos, bom o papo e o seguinte");
                al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "temos que acertar a porta certa em cada sala");
                al_draw_text(font2,al_map_rgb(255,255,255),250,85, ALLEGRO_ALIGN_CENTRE, "a cada 7 niveis teremos um desafio extra, na");
                al_draw_text(font2,al_map_rgb(255,255,255),250,110, ALLEGRO_ALIGN_CENTRE, "lembre-se da resposta de cada nivel, isso");
                al_draw_text(font2,al_map_rgb(255,255,255),250,135, ALLEGRO_ALIGN_CENTRE, "pode ser de grande ajuda, e para o final na");
                al_draw_text(font2,al_map_rgb(255,255,255),250,160, ALLEGRO_ALIGN_CENTRE, "ultima fase teremos de descobrir o que realmente");
                al_draw_text(font2,al_map_rgb(255,255,255),250,185, ALLEGRO_ALIGN_CENTRE, "aconteceu na nossa noite... (flashback time)");
                al_draw_text(font2,al_map_rgb(255,255,255),350,400, ALLEGRO_ALIGN_CENTRE, "Press Enter to continue");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(textbox,400,100,0);
              }
              if(txt==4)
              ex=1;
              al_flip_display();
              desenha=0;
            
        }//fim loop
        int flashback=0;
        colunas=6;
        frames=10;
        frameatu=0;
        catu=0;
        posy=510;
        al_clear_to_color(al_map_rgb(0,255,0));
        al_draw_filled_circle(540,500,150,al_map_rgb(0,0,0));
        al_flip_display();
        while(!flashback){
            al_convert_mask_to_alpha(a,al_map_rgb(0,0,0));
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila,&evento);
            if(evento.type==ALLEGRO_EVENT_TIMER){
              
                  frameatu++;
                  if(frameatu >= frames){
                      frameatu=0;
                      catu++;
                      if(catu>= colunas){
                      catu=0;
                      }
                      regiaox=catu*largura;
                      
                  }
                  posy+=1;
                  desenha=1;
              }
              if(desenha){
                  al_set_target_bitmap(newspr);
                  al_clear_to_color(al_map_rgb(0,0,0));
                  al_draw_bitmap_region(a,regiaox,regiaoy,largura,altura,0,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(newspr,500,posy,0);
              }
              al_flip_display();
              if(posy>=650) flashback=1;
              
              
        }
            
        
        
        }
    
    struct rnk{
        int pont;
        char nom[50];
        };
    
    typedef struct rnk RK;
    
    void ranking(char *nome,int pontos){
        FILE *f;
        int i;
        RK *v;
        v=(RK*) malloc(10*sizeof(RK));
    	f= fopen("rnk.txt","r+b");
    	if(f==NULL){
    		RK a;
    		a.pont=0;
    		a.nom[0]='A';
    		a.nom[1]='A';
    		a.nom[2]='A';
    		a.nom[3]='\0';
    		fclose(f);
    		f= fopen("rnk.txt","w+b");
    		for(i=0;i<10;i++)
    		fwrite(&a,sizeof(RK),1,f);
    		rewind(f);
    	}
    	
    	for(i=0;i<10;i++){
    		fread(&v[i],sizeof(RK),1,f);
    		printf("%d: %s %d\n",i,v[i].nom,v[i].pont);
    	}
    	printf("ELE CRIOU O RANKING\n");
    	fclose(f);
    	int pos,entraOUnaoNoRanking=0,verpont=0,vernome=0;
    	int j=0;
    	while(!verpont){
            if(v[j].pont<pontos){
            pos=j;
            entraOUnaoNoRanking=1;
            verpont=1;
            }
            
            j++;    
            if(j==10)
            verpont=1;
        }
        int k=0;
        int oldPlayer=0,oldpos;
        
        if(entraOUnaoNoRanking){
            while(!vernome){
                if(!strcmp(v[k].nom,nome)){
                    oldPlayer=1;
                    vernome=1;
                    printf("existe nome\n%d\n",k);
                    if(v[k].pont<=pontos)
                    pos=k;
                }
                k++;
                if(k==10)
                vernome=1;
            }
            if(!oldPlayer){
                //passando todos os valores 1 posicao pra baixo
                for(i=9;i>pos;i--){
                    strcpy(v[i].nom,v[i-1].nom);
                    v[i].pont=v[i-1].pont;
                }
            }
            printf("%d",pos);
            strcpy(v[pos].nom,nome);
            v[pos].pont=pontos;
        }
        f= fopen("rnk.txt","wb");
        for(i=0;i<10;i++){
    		fwrite(&v[i],sizeof(RK),1,f);
    	}
    	fclose(f);
    	al_clear_to_color(al_map_rgb(0,255,0));
    	int h=60;
    	al_draw_text(font,al_map_rgb(255,255,255),150, 20, ALLEGRO_ALIGN_CENTRE,"Player:");
    	al_draw_text(font,al_map_rgb(255,255,255),940, 20, ALLEGRO_ALIGN_CENTRE,"Pontos:");
    	for(i=0;i<10;i++){
    	al_draw_textf(font,al_map_rgb(255,255,255),150, h, ALLEGRO_ALIGN_CENTRE,"%s", v[i].nom);
    	al_draw_text(font,al_map_rgb(255,255,255),540, h, ALLEGRO_ALIGN_CENTRE,"..........................................................................");
    	al_draw_textf(font,al_map_rgb(255,255,255),940, h, ALLEGRO_ALIGN_CENTRE,"%d", v[i].pont);
    	h+=50;
        }
        al_draw_text(font,al_map_rgb(255,255,255),750, 560, ALLEGRO_ALIGN_CENTRE,"Press Enter to Exit");
        al_flip_display();
    	
    	int sair=0;
    	while(!sair){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila,&evento);
            
            
            if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                   destroir();
              }
            if(evento.type==ALLEGRO_EVENT_KEY_DOWN){
                   if(evento.keyboard.keycode==ALLEGRO_KEY_ENTER)
                   sair=1;
            }
            
        }
        
        
}
     
     //minijogo 1
     
     
     
     
int isThereCollision(float b1_x, float b1_y, int b1_w, int b1_h, float b2_x, float b2_y, int b2_w, int b2_h){
    if((b1_x > b2_x + b2_w - 1) ||
       (b1_y > b2_y + b2_h - 1) ||
       (b2_x > b1_x + b1_w - 1) ||
       (b2_y > b1_y + b1_h - 1))
        return 0;
    return 1;
}

int minijojo1(int *dica){    // MUDA O NOME DA FUNÇÃO PARA O NOME QUE VOCÊ FOR UTILIZAR
    
    ALLEGRO_BITMAP *window = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_BITMAP *firstDash = NULL;
    ALLEGRO_BITMAP *secondDash = NULL;
    ALLEGRO_BITMAP *ball = NULL;
    const float FPS = 60.f;
    const int DASH_WIDTH = 12, DASH_HEIGHT = 48, BALL_WIDTH = 6, BALL_HEIGHT = 6;
    float firstDash_x = WIDTH - DASH_WIDTH - 4.f, firstDash_y = HEIGHT/2 - DASH_HEIGHT/2, secondDash_x = 4.f, secondDash_y = HEIGHT/2 - DASH_HEIGHT/2;
    float Dash_dy = 4.f;
    float ball_x = WIDTH / 2.f, ball_y = HEIGHT / 2.f, ball_dx = -4.f, ball_dy = 4.f;
    int firstPoints = 0, secondPoints = 0;
    bool redraw = 1, doexit = 0;
    enum MYKEYS {KEY_UP, KEY_DOWN, KEY_W, KEY_S};
    bool key[4] = {0, 0, 0, 0}; 

    if(!al_init()){
        fprintf(stderr, "error\n");
        return -1;
    }

    if(!al_install_keyboard()){
        fprintf(stderr, "error\n");
        return -1;
    }
    
    al_init_font_addon();
    al_init_ttf_addon();
    
    timer = al_create_timer(1.f/FPS);
    if(!timer){
        fprintf(stderr, "error\n");
        return -1;
    }

    window = al_create_bitmap(WIDTH, HEIGHT);
    if(!window){
        fprintf(stderr, "error\n");
        al_destroy_timer(timer);
        return -1;
    }

    firstDash = al_create_bitmap(DASH_WIDTH, DASH_HEIGHT);
    if(!firstDash){
        fprintf(stderr, "error\n");
        al_destroy_timer(timer);
        //al_destroy_display(window);
        return -1;
    }

    secondDash = al_create_bitmap(DASH_WIDTH, DASH_HEIGHT);
    if(!secondDash){
        fprintf(stderr, "error\n");
        al_destroy_timer(timer);
        al_destroy_bitmap(firstDash);
        //al_destroy_display(window);
        return -1;
    }

    ball = al_create_bitmap(BALL_WIDTH, BALL_HEIGHT);
    if(!ball){
        fprintf(stderr, "error\n");
        al_destroy_timer(timer);
        al_destroy_bitmap(firstDash);
        al_destroy_bitmap(secondDash);
        //al_destroy_display(window);
        return -1;
    }

    // COLORING FIRST DASH.
    al_set_target_bitmap(firstDash);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    
    // COLORING SECOND DASH.
    al_set_target_bitmap(secondDash);
    al_clear_to_color(al_map_rgb(255, 255, 255)); 
    
    // COLORING BALL.
    al_set_target_bitmap(ball);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_target_bitmap(al_get_backbuffer(display));    

    
    event_queue = al_create_event_queue();
    if(!event_queue){
        fprintf(stderr, "error\n");
        al_destroy_timer(timer);
        al_destroy_bitmap(firstDash);
        al_destroy_bitmap(secondDash);
        al_destroy_bitmap(ball);
        //al_destroy_display(window);
        return -1;
    }

    font = al_load_ttf_font("Arial.ttf", 36, 0);

    // REGISTERING ALL POSSIBLE SOURCES OF EVENTS.
    //al_register_event_source(event_queue, al_get_display_event_source(window));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // MAKING THE BACKGROUND BLACK.
    al_set_target_bitmap(window);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(window, 220, 80, 0);
    al_flip_display();
    al_start_timer(timer);
    
    // MAIN LOOP.
    while(!doexit){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER){
            /*if(key[KEY_UP] && firstDash_y >= 4.f)
                firstDash_y -= 4.f;
            if(key[KEY_DOWN] && firstDash_y <= HEIGHT - DASH_HEIGHT - 4.f) 
                firstDash_y += 4.f;*/
            if(firstDash_y == 0 || firstDash_y == HEIGHT - DASH_HEIGHT)            
                Dash_dy *= -1;
            if(key[KEY_W] && secondDash_y >= 4.f)
                secondDash_y -= 4.f;
            if(key[KEY_S] && secondDash_y <= HEIGHT - DASH_HEIGHT - 4.f)
                secondDash_y += 4.f;
            if(ball_y <= 0 || ball_y >= HEIGHT - BALL_HEIGHT)
                ball_dy *= -1;
            if(ball_x <= 0 || ball_x >= WIDTH - BALL_WIDTH){
                ball_dx *= -1;
                ball_x <= 0 ? firstPoints++ : secondPoints++;
            }
            if(isThereCollision(ball_x, ball_y, BALL_WIDTH, BALL_HEIGHT, firstDash_x, firstDash_y, DASH_WIDTH, DASH_HEIGHT))
                ball_dx *= -1;
            if(isThereCollision(ball_x, ball_y, BALL_WIDTH, BALL_HEIGHT, secondDash_x, secondDash_y, DASH_WIDTH, DASH_HEIGHT))
                ball_dx *= -1;            
            if(firstPoints == 3 || secondPoints == 3){
                al_set_target_bitmap(window);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_textf(font, al_map_rgb(255, 255, 255), WIDTH/2, HEIGHT/2 - 24, ALLEGRO_ALIGN_CENTRE, firstPoints == 3 ? "YOU LOST" : "YOU WON");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(window, 220, 80, 0);
                al_flip_display();
                *dica = (firstPoints==3)?1:0;
                al_rest(2.f);
                //break;
                doexit=1;
            }
            
            firstDash_y += Dash_dy;
            ball_x += ball_dx;
            ball_y += ball_dy;
            redraw = 1;        
        }        
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(ev.keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = 1;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = 1;
                    break;
                case ALLEGRO_KEY_W:
                    key[KEY_W] = 1;
                    break;
                case ALLEGRO_KEY_S:
                    key[KEY_S] = 1;
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP){
            switch(ev.keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = 0;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = 0;
                    break;
                case ALLEGRO_KEY_W:
                    key[KEY_W] = 0;
                    break;
                case ALLEGRO_KEY_S:
                    key[KEY_S] = 0;
                    break;
            }
        }
        if(redraw && al_is_event_queue_empty(event_queue)){
            redraw = 0;
            al_set_target_bitmap(window);
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_textf(font, al_map_rgb(255, 255, 255), WIDTH/2, HEIGHT/8, ALLEGRO_ALIGN_CENTRE, "%d x %d", secondPoints, firstPoints);
            al_draw_bitmap(firstDash, firstDash_x, firstDash_y, 0);
            al_draw_bitmap(secondDash, secondDash_x, secondDash_y, 0);
            al_draw_bitmap(ball, ball_x, ball_y, 0);
            al_set_target_bitmap(al_get_backbuffer(display));
            al_draw_bitmap(window, 220, 80, 0);
            al_flip_display();
        }
    }
    
}
//fim minijojo


//inicio minijojo2



bool areSameArray(bool **terrainBomb, bool **terrainBool){
    int i,j;
    for(i = 0; i < SIZEARR; i++){
        for(j = 0; j < SIZEARR; j++){
            if(terrainBool[i][j] != terrainBomb[i][j])
                return 0;
        }
    }
    return 1;
}

int checkNearbySquares(bool **terrainBomb, int m, int n){
    int totalBombs = 0;
    if(m > 0)
        totalBombs += terrainBomb[m-1][n];
    if(n > 0)
        totalBombs += terrainBomb[m][n-1];
    if(m > 0 && n > 0)
        totalBombs += terrainBomb[m-1][n-1];
    if(m < SIZEARR - 1)
        totalBombs += terrainBomb[m+1][n];
    if(n < SIZEARR - 1)
        totalBombs += terrainBomb[m][n+1];
    if(m < SIZEARR - 1 && n < SIZEARR - 1)
        totalBombs += terrainBomb[m+1][n+1];
    if(m > 0 && n < SIZEARR - 1)
        totalBombs += terrainBomb[m-1][n+1];
    if(m < SIZEARR - 1 && n > 0)
        totalBombs += terrainBomb[m+1][n-1];
    
    return totalBombs;
}

int minijojo2(int *dica){
    int i,j;
    srand(time(NULL));
    ALLEGRO_BITMAP *window = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *font = NULL;
    
    // VARIÁVEIS NECESSÁRIAS.
    ALLEGRO_BITMAP ***terrain = (ALLEGRO_BITMAP ***)malloc(sizeof(ALLEGRO_BITMAP **) * SIZEARR);
    for( i = 0; i < 10; i++)
        terrain[i] = (ALLEGRO_BITMAP **)malloc(sizeof(ALLEGRO_BITMAP *) * SIZEARR);
    bool **terrainBool = (bool **)malloc(sizeof(bool *) * SIZEARR);
    for( i = 0; i < 10; i++)
        terrainBool[i] = (bool *)malloc(sizeof(bool) * SIZEARR);
    bool **terrainBomb = (bool **)malloc(sizeof(bool *) * SIZEARR);
    for( i = 0; i < 10; i++)
        terrainBomb[i] = (bool *)malloc(sizeof(bool) * SIZEARR);
    bool redraw = 1;
    int dificuldade = 15;
    int offsetY=80,offsetX=220;
    // INICIALIZAÇÕES.
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    if(!al_install_mouse()) {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }    
    if(!al_init_image_addon()) {
        fprintf(stderr, "failed to initialize images.\n");
        return -1;
   }
    
    timer = al_create_timer(1.f/60.f);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    window = al_create_bitmap(WIDTH, HEIGHT);
    if(!window) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }    
    
    font = al_load_ttf_font("Arial.ttf", 20, 0);
    if (!font){
        fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
        //al_destroy_display(window);
        al_destroy_timer(timer);
        return -1;
    }

    for( i = 0; i < SIZEARR; i++){
        for( j = 0; j < SIZEARR; j++){
            terrain[i][j] = al_load_bitmap("mine.bmp");
            terrainBool[i][j] = 1;
            if(rand() % 99 < dificuldade)
                terrainBomb[i][j] = 1;
            else
                terrainBomb[i][j] = 0;
            fprintf(stdout, "%3d", terrainBomb[i][j]);
        }
        fprintf(stdout, "\n");
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        //al_destroy_display(window);
        al_destroy_font(font);
        al_destroy_timer(timer);
        return -1;
    }

    //al_register_event_source(event_queue, al_get_display_event_source(window));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    // AJEITANDO A TELA.
    al_set_target_bitmap(al_get_backbuffer(display));
    al_set_target_bitmap(window);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(window, 220, 80, 0);
    al_flip_display();
    al_start_timer(timer);
    int ex=0;
    while(!ex){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);        

        if(ev.type == ALLEGRO_EVENT_TIMER)
            redraw = 1;
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            
             if(terrainBomb[(int)floor(ev.mouse.y / (80+(HEIGHT/10)))][(int)floor(ev.mouse.x / (220+(WIDTH/10)))]){
                al_set_target_bitmap(window);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_textf(font, al_map_rgb(255, 255, 255), offsetX + WIDTH/2, offsetY + HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "YOU LOST");
                terrain[(int)floor(ev.mouse.y / (HEIGHT/10 + offsetY))][(int)floor(ev.mouse.x / (WIDTH/10 + offsetX))] = al_load_bitmap("bomb_found.bmp");
                al_draw_bitmap(terrain[(int)floor(ev.mouse.y / (HEIGHT/10 + offsetY))][(int)floor(ev.mouse.x / (WIDTH/10 + offsetX))], ev.mouse.x, ev.mouse.y, 0);
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(window, 220, 80, 0);
                al_flip_display();
                *dica=0;
                al_rest(1.5);
                break;
            }
            else
                terrainBool[(int)floor(ev.mouse.y / (offsetY+(HEIGHT/10)))][(int)floor(ev.mouse.x / (offsetX+(WIDTH/10)))] = 0;
        }
        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = 0;
            al_set_target_bitmap(window);
            al_clear_to_color(al_map_rgb(0,0,0));
            al_set_target_bitmap(al_get_backbuffer(display));
            al_draw_bitmap(window, 220, 80, 0);
            for( i = 0; i < SIZEARR; i++){
                for( j = 0; j < SIZEARR; j++){
                    al_set_target_bitmap(window);
                    if(!terrainBool[i][j])
                        terrain[i][j] = al_load_bitmap("mine_gone.bmp");
                    al_draw_bitmap(terrain[i][j], j*WIDTH/10, i*HEIGHT/10, 0);
                    if(!terrainBool[i][j])
                        al_draw_textf(font, al_map_rgb(255, 0, 0), j*WIDTH/10 + WIDTH/20, i*HEIGHT/10 + HEIGHT/40, ALLEGRO_ALIGN_CENTRE, "%d", checkNearbySquares(terrainBomb, i, j));
                    al_set_target_bitmap(al_get_backbuffer(display));
                    al_draw_bitmap(window, 220, 80, 0);
                }
            }  /// TODO: E SE O CARA CONSEGUIR TERMINAR.
            
            if(areSameArray(terrainBomb, terrainBool)){
                al_set_target_bitmap(window);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_textf(font, al_map_rgb(255, 255, 255), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "YOU WON!");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(window, 220, 80, 0);
                al_flip_display();
                al_rest(1.5);
                *dica=1;
                break;
            }
            al_flip_display();
        }
    }
}

//fim minijojo2


//inicio minijojo3


 
 // just creating an error msg 
 


void starti(){
    ALLEGRO_BITMAP *window = NULL;
    window = al_create_bitmap(640, 480);
       al_set_target_bitmap(window);
       al_clear_to_color(al_map_rgb(0,0,0));
       al_draw_rectangle(170,90,470,390,al_map_rgb(255,255,255),10);
       al_draw_line(270,90,270,390,al_map_rgb(255,255,255),10);
       al_draw_line(370,90,370,390,al_map_rgb(255,255,255),10);
       al_draw_line(170,190,470,190,al_map_rgb(255,255,255),10);
       al_draw_line(170,290,470,290,al_map_rgb(255,255,255),10);
       al_set_target_bitmap(al_get_backbuffer(display));
       al_draw_bitmap(window, 220, 80, 0);
       al_flip_display();
    }
    
    void enemy(int jogada[3][3],int *wi){
        ALLEGRO_BITMAP *window = NULL;
        window = al_create_bitmap(640, 480);
       al_set_target_bitmap(window);
        srand(time(NULL));
        int h=90,w=170;
        int l,c,s_n=0,i,j;
        s_n=0;
        for(j=0;j<3;j++){
            for(i=0;i<3;i++){
                  if(jogada[j][i]!=0)
                     s_n++;
            }
        }
        if(s_n!=9){
            label:
               l=rand()%3;
               c=rand()%3;
               printf("enemy:%d %d\n",l,c);
            if(jogada[l][c]){
                 
                 goto label;
                 }
            switch(c){
                      case 1:
                           w+=100;
                           break;
                      case 2:
                           w+=200;
                           break;
            }
            switch(l){
                          case 1:
                               h+=100;
                               break;
                          case 2:
                               h+=200;
                               break;
            }
            
            al_draw_circle(w+100/2,h+100/2,45,al_map_rgb(255,0,0),10);
            al_set_target_bitmap(al_get_backbuffer(display));
            al_draw_bitmap(window, 220, 80, 0);
            al_flip_display();
            jogada[l][c]=2;
        }
        else
            *wi=2;

}

void win(int jog[3][3],bool *w,int *what){
   int i,j,h=90,wii=170,draw;
   printf("\n%d\n",*w);
   draw=0;
   ALLEGRO_BITMAP *window = NULL;
        window = al_create_bitmap(640, 480);
       al_set_target_bitmap(window);
        
   for(j=0;j<3;j++){
           if(jog[j][0]==jog[j][1] && jog[j][0] == jog[j][2]&&(jog[j][0]==1||jog[j][0]==2)){
                   *w=1;
                   al_draw_line(170,h+50,470,h+50,al_map_rgb(255,255,255),10);
           }
           if(jog[0][j] == jog[1][j] && jog[0][j] == jog[2][j]&&(jog[0][j]==1||jog[0][j]==2)){
                   *w=1;
                   al_draw_line(wii+50,90,wii+50,390,al_map_rgb(255,255,255),10);                   
           }
           h+=100;
           wii+=100;
   }  
   if(jog[0][0]==jog[1][1]&&jog[0][0]==jog[2][2]&&(jog[0][0]==1||jog[0][0]==2)){
           *w=1;
           al_draw_line(170,90,470,390,al_map_rgb(255,255,255),10);
   }
   
   if(jog[0][2]==jog[1][1]&&jog[0][2]==jog[2][0]&&(jog[0][2]==1||jog[0][2]==2)){
           *w=1;//285 65
           al_draw_line(470,90,170,390,al_map_rgb(255,255,255),10);
   }
   if(*w!=1){
       for(j=0;j<3;j++){
                for(i=0;i<3;i++){
                      if(jog[j][i]==0)
                         draw++;
                }
       }
       if(draw==0){
            *what=2;
            *w=1;
            printf("%d",*what);
       }
   }
   //return *w;
   al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(window, 220, 80, 0);
   al_flip_display(); 
   
}

int cabo(int *n,int w_l,int jogada[3][3],bool *w,int *player,int *cont){
    ALLEGRO_BITMAP *window = NULL;
    window = al_create_bitmap(640, 480);
    int j,i,op=0;
    al_set_target_bitmap(window);
    al_clear_to_color(al_map_rgb(0,0,0));
        if(w_l==0)
        al_draw_text(font2,al_map_rgb(255,255,255),320, 240, ALLEGRO_ALIGN_CENTRE, "YOU WIN");
        else if(w_l==1)
        al_draw_text(font2,al_map_rgb(255,255,255),320, 240, ALLEGRO_ALIGN_CENTRE, "YOU LOSE");
        else if(w_l==2)
        al_draw_text(font2,al_map_rgb(255,255,255),320, 240, ALLEGRO_ALIGN_CENTRE, "ITS A DRAW");
        al_set_target_bitmap(al_get_backbuffer(display));
        al_draw_bitmap(window, 220, 80, 0);
        al_flip_display();
        al_rest(2);
    *n=1;
 }

int minijojo3(int *dica)
{
    // set all the things that we ill use NULL, seems like a good idea
ALLEGRO_BITMAP *window = NULL;
ALLEGRO_EVENT_QUEUE *KKK = NULL;
ALLEGRO_BITMAP *q=NULL,*imagee=NULL;
ALLEGRO_FONT *font       = NULL;
 //this  its just to see if there is some error while initializing anything, we set all NULL of course 
    if (!al_init()){
        error_msg("Error in Allegro initializating");
        return 0;
    }
    
    if(!al_init_primitives_addon()){
        error_msg("Error in drawing initializating");
        return 0;                          
    } 

    if (!al_install_keyboard()){
        error_msg("Error in Keyboard initializating");
        return 0;
    }
    
    window = al_create_bitmap(640, 480);
    if (!window){
        error_msg("Error in display creating");
        return 0;
    }  
    //this is to change my title
    //al_set_window_title(display, "Jogson bb");
    
    KKK = al_create_event_queue();
    if (!KKK){
        error_msg("Error in the event queue");
        al_destroy_display(display);
        return 0;
    }
    
    //new things now for mouse
    if (!al_install_mouse()){
        error_msg("Error in mouse installing");
        al_destroy_display(display);
        return 0;
    }
    if (!al_set_system_mouse_cursor(display,ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        error_msg("Error in mouse setting");
        al_destroy_display(display);
        return 0;
    }  
    
    al_init_image_addon();
    if(!al_init_image_addon()){
        error_msg("Error in image initializating");
        return 0;                          
    }
    
    
    
    //criando um cubo em bitmap para cada quadrado do jogo
     q = al_create_bitmap(150,100);
     if (!q){
       error_msg("Error in bitmap creating");
       al_destroy_display(display);
       return -1;
     }
    
    //there is a event register, in this case of the keyboard and display
    al_register_event_source(KKK, al_get_keyboard_event_source());
    al_register_event_source(KKK, al_get_mouse_event_source()); 
 
    srand(time(NULL));
    int ex,i,j,menu=0,qunt=0,choice=0,player=0,cont=0,s=0;
    bool w_l=0;
    int what=0;
    int jogada[3][3]={0,0,0,0,0,0,0,0,0};
    
       starti();
   
    ex=0; 
    int h=170,w=390,turn=0;
    while(!ex){       
           
      
           
                        while(!turn){   
                                                                      
                           ALLEGRO_EVENT evento;
                           al_wait_for_event(KKK,&evento);
                           if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                            ex++;
                            turn++;
                            }
                            h=170,w=390;
                           // i just create a boolean event for each square, with this i can recognize wich square am i clicking;
                           bool onde[3][3];
                           for(j=0;j<3;j++){
                               for(i=0;i<3;i++){
                                                onde[j][i]=(evento.mouse.x<=w+100&&evento.mouse.x>=w&&evento.mouse.y<=h+100&&evento.mouse.y>=h);
                                                w+=100;           
                               }
                               w=390;
                               h+=100;
                           }
                           h=90,w=170;
                           
                           //Your turn
                           if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                                       qunt++;
                                printf("no turno");
                                   for(j=0;j<3;j++){           
                                          for(i=0;i<3;i++){
                                                  if(onde[j][i]&&!jogada[j][i]){
                                                             jogada[j][i]=1;   
                                                             al_set_target_bitmap(window);
                                                             al_draw_line(w,h,w+100,h+100,al_map_rgb(255,0,0),10);
                                                             al_draw_line(w+100,h,w,h+100,al_map_rgb(255,0,0),10);
                                                             al_set_target_bitmap(al_get_backbuffer(display));
                                                             al_draw_bitmap(window, 220, 80, 0);
                                                             printf("%d %d %d\n",j,i,jogada[j][i]);
                                                             turn++;
                                                             //break;
                                                  }    
                                                  w+=100;
                                          }  
                                       w=170;
                                       h+=100;
                                   }   
                           }
                           
                            
                      }
                      
     //fim da jogada
      al_flip_display();
      win(jogada,&w_l,&what);
      printf("\nbool: %d\n",w_l);
      if(w_l){
              if(what!=2) what = 0;
               cabo(&ex,what,jogada,&w_l,&player,&cont);
               *dica=what;
            al_rest(2);
             goto label;
      }  
           al_rest(0.5);
           enemy(jogada,&what);
       
      
      //al_rest(3);
      win(jogada,&w_l,&what);
      printf("bool: %d\n",w_l);
      if(w_l){
            if(what!=2) what = 1;
                 cabo(&ex,what,jogada,&w_l,&player,&cont);
                 *dica=what;
                 al_rest(2);
      }     
      what=0;
             
      for(j=0;j<3;j++){
             for(i=0;i<3;i++)
                  printf("%d",jogada[j][i]);
             printf("\n");
      }
      
      turn=0;
      int l;
    label:
       l=0;
    }

}
//fim de minijojo 3



//minijojo 4

void fillList(int list[][3], int chosenIndex){
    int i,j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 3; j++){
            if(i == chosenIndex)
                list[i][j] = (list[0][j] + list[1][j])/2;
            else
                list[i][j] = rand() % 256;
        }
    }  
}

int minijojo4(int *dica){
    srand(time(NULL));
    ALLEGRO_BITMAP*window = NULL;
    ALLEGRO_FONT *font, *font2 = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *leftColor = NULL, *rightColor = NULL;
    ALLEGRO_BITMAP *LTColor = NULL, *RTColor = NULL, *LBColor = NULL, *RBColor = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    int colorList[6][3], chosenIndex = 3, pointsFor = 0, pointsAgainst = 0;
    const int color_dim = 100, color_offsetx = 330, color_offsety = 110;
    const int leftColor_dim[2] = {WIDTH/4 - color_dim, HEIGHT/4 - color_dim}, rightColor_dim[2] = {3*WIDTH/4 - color_dim, HEIGHT/4 - color_dim};
    bool redraw = 1;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    if(!al_install_mouse()) {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }
    timer = al_create_timer(1.f/60.f);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    window = al_create_bitmap(WIDTH, HEIGHT);
    if(!window) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }
    font = al_load_ttf_font("Arial.ttf", 96, 0);
    font2 = al_load_ttf_font("Arial.ttf", 24, 0);
    if (!font){
        fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
        //al_destroy_display(window);
        al_destroy_timer(timer);
        return -1;
    }

    
    
    leftColor = al_create_bitmap(color_dim, color_dim);
    al_set_target_bitmap(leftColor);
    al_clear_to_color(al_map_rgb(colorList[0][0], colorList[0][1], colorList[0][2]));

    rightColor = al_create_bitmap(color_dim, color_dim);
    al_set_target_bitmap(rightColor);
    al_clear_to_color(al_map_rgb(colorList[1][0], colorList[1][1], colorList[1][2]));

    LTColor = al_create_bitmap(color_dim, color_dim);
    al_set_target_bitmap(LTColor);
    al_clear_to_color(al_map_rgb(colorList[2][0], colorList[2][1], colorList[2][2])); 

    RTColor = al_create_bitmap(color_dim, color_dim);
    al_set_target_bitmap(RTColor);
    al_clear_to_color(al_map_rgb((colorList[0][0]+colorList[1][0])/2, (colorList[0][1]+colorList[1][1])/2, (colorList[0][2]+colorList[1][2])/2)); // O PRIMEIRO ESCOLHIDO É SEMPRE O RT.

    LBColor = al_create_bitmap(color_dim, color_dim);
    al_set_target_bitmap(LBColor);
    al_clear_to_color(al_map_rgb(colorList[4][0], colorList[4][1], colorList[4][2]));

    RBColor = al_create_bitmap(color_dim, color_dim);
    al_set_target_bitmap(RBColor);
    al_clear_to_color(al_map_rgb(colorList[5][0], colorList[5][1], colorList[5][2]));
    al_set_target_bitmap(al_get_backbuffer(display));  
    
    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
       // al_destroy_display(window);
        al_destroy_timer(timer);
        return -1;
    }
       
    //al_register_event_source(event_queue, al_get_display_event_source(window));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source()); 
    
    al_set_target_bitmap(window);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(window,220,80,0);
    al_flip_display();
    al_start_timer(timer);

    while(1){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_TIMER)
            redraw = 1;
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if((ev.mouse.x >= color_offsetx && ev.mouse.x <= color_offsetx + color_dim) && (ev.mouse.y >= HEIGHT/3 + color_offsety && ev.mouse.y <= HEIGHT/3 + color_offsety + color_dim)){
                if(chosenIndex == 2){
                    chosenIndex = (rand() % 4) + 2;
                    pointsFor++;
                    fillList(colorList, chosenIndex);
                }
                else
                    pointsAgainst++;   
            }
            else if((ev.mouse.x >= 3*(color_offsetx-220 )+ color_dim+220 && ev.mouse.x <= 3*(color_offsetx-220) + color_dim + color_dim+220) && (ev.mouse.y >= HEIGHT/3 + color_offsety && ev.mouse.y <= HEIGHT/3 + color_offsety + color_dim)){
                if(chosenIndex == 3){
                    chosenIndex = (rand() % 4) + 2;
                    pointsFor++;
                    fillList(colorList, chosenIndex);
                } 
                else
                    pointsAgainst++; 
            }
            else if((ev.mouse.x >= color_offsetx && ev.mouse.x <= color_offsetx + color_dim) && (ev.mouse.y >= 2*HEIGHT/3 + color_offsety && ev.mouse.y <= 2*HEIGHT/3 + color_offsety + color_dim)){
                if(chosenIndex == 4){
                    chosenIndex = (rand() % 4) + 2;
                    pointsFor++;
                    fillList(colorList, chosenIndex);
                } 
                else
                    pointsAgainst++;  
            }
            else if((ev.mouse.x >= 3*(color_offsetx-220 )+ color_dim+220 && ev.mouse.x <= 3*(color_offsetx-220) + color_dim + color_dim+220) && (ev.mouse.y >= 2*HEIGHT/3 + color_offsety && ev.mouse.y <= 2*HEIGHT/3 + color_offsety + color_dim)){
                if(chosenIndex == 5){
                    chosenIndex = (rand() % 4) + 2;
                    pointsFor++;
                    fillList(colorList, chosenIndex);
                }
                else
                    pointsAgainst++;  
            }
        }
        if(redraw && al_is_event_queue_empty(event_queue)){
            redraw = 0;
            al_set_target_bitmap(window);
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_set_target_bitmap(al_get_backbuffer(display));
            al_draw_bitmap(window,220,80,0);
            leftColor = al_create_bitmap(color_dim, color_dim);
            al_set_target_bitmap(leftColor);
            al_clear_to_color(al_map_rgb(colorList[0][0], colorList[0][1], colorList[0][2]));
        
            rightColor = al_create_bitmap(color_dim, color_dim);
            al_set_target_bitmap(rightColor);
            al_clear_to_color(al_map_rgb(colorList[1][0], colorList[1][1], colorList[1][2]));
        
            LTColor = al_create_bitmap(color_dim, color_dim);
            al_set_target_bitmap(LTColor);
            al_clear_to_color(al_map_rgb(colorList[2][0], colorList[2][1], colorList[2][2])); 
        
            RTColor = al_create_bitmap(color_dim, color_dim);
            al_set_target_bitmap(RTColor);
            al_clear_to_color(al_map_rgb((colorList[0][0]+colorList[1][0])/2, (colorList[0][1]+colorList[1][1])/2, (colorList[0][2]+colorList[1][2])/2)); // O PRIMEIRO ESCOLHIDO É SEMPRE O RT.
        
            LBColor = al_create_bitmap(color_dim, color_dim);
            al_set_target_bitmap(LBColor);
            al_clear_to_color(al_map_rgb(colorList[4][0], colorList[4][1], colorList[4][2]));
        
            RBColor = al_create_bitmap(color_dim, color_dim);
            al_set_target_bitmap(RBColor);
            al_clear_to_color(al_map_rgb(colorList[5][0], colorList[5][1], colorList[5][2]));
            
            al_set_target_bitmap(window);
            al_draw_bitmap(leftColor, leftColor_dim[0], leftColor_dim[1], 0);
            al_draw_bitmap(rightColor, rightColor_dim[0], rightColor_dim[1], 0);
            al_draw_textf(font, al_map_rgb(255, 255, 255), WIDTH/2 - color_dim/2, leftColor_dim[1], ALLEGRO_ALIGN_CENTRE, "+");
            al_draw_textf(font, al_map_rgb(255, 255, 255), WIDTH - 2*color_dim/3, leftColor_dim[1], ALLEGRO_ALIGN_CENTRE, "?");

            al_draw_bitmap(LTColor, color_offsetx-220, HEIGHT/3 + color_offsety-80, 0);
            al_draw_bitmap(RTColor, 3*(color_offsetx-220) + color_dim, HEIGHT/3 + color_offsety-80, 0);
            al_draw_bitmap(LBColor, color_offsetx-220, 2*HEIGHT/3 + color_offsety-80, 0);
            al_draw_bitmap(RBColor, 3*(color_offsetx-220) + color_dim, 2*HEIGHT/3 + color_offsety-80, 0);

            al_draw_textf(font2, al_map_rgb(255, 255, 255), WIDTH/4, HEIGHT - 30, ALLEGRO_ALIGN_CENTRE, "right: %d", pointsFor);
            al_draw_textf(font2, al_map_rgb(255, 255, 255), 3*WIDTH/4, HEIGHT - 30, ALLEGRO_ALIGN_CENTRE, "wrong: %d", pointsAgainst);
            
            al_set_target_bitmap(al_get_backbuffer(display));
            al_draw_bitmap(window,220,80,0);
            if(pointsFor >= 3){
                al_draw_textf(font2, al_map_rgb(255, 255, 255), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "YOU WON");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(window,220,80,0);
                al_flip_display();
                *dica=1;
                al_rest(1.5);
                break;
            }
            else if(pointsAgainst >= 3){
                al_set_target_bitmap(window);
                al_draw_textf(font2, al_map_rgb(255, 255, 255), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "YOU LOST");
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(window,220,80,0);
                al_flip_display();
                *dica=0;
                al_rest(1.5);
                break;
            }

            al_flip_display();
        }
    }
}

//fim minijojo 4

//introducao minijojo

void intro(int choichoi,int time){
    ALLEGRO_BITMAP *a;
     al_clear_to_color(al_map_rgb(0,0,0));
     al_flip_display();
        if(choichoi==1){
            a= dance1;   
        }
        if(choichoi==2){
            a= dance2;   
        }
        if(choichoi==3){
            a= dance3;   
        }
        if(choichoi==4){
            a= dance4;   
        }
        if(choichoi==5){
            a= dance5;   
        }
        if(choichoi==6){
            a= dance6;
        }
        int colunas=7;
        int frames=10;
        int frameatu=0;
        int catu=0,regiaox=0;
        int largura=64,altura=64;
        int ex=0;
        int desenha;
        while(!ex){
                al_convert_mask_to_alpha(a,al_map_rgb(0,0,0));
                ALLEGRO_EVENT evento;
                al_wait_for_event(fila,&evento);
                
                
                if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                       destroir();
                  } 
                if(evento.type==ALLEGRO_EVENT_KEY_DOWN){
                    if(evento.keyboard.keycode==ALLEGRO_KEY_ENTER){
                        ex++;
                    }
                }
                if(evento.type==ALLEGRO_EVENT_TIMER){
                  
                      frameatu++;
                      if(frameatu >= frames){
                          frameatu=0;
                          catu++;
                          if(catu>= colunas){
                          catu=0;
                          }
                          regiaox=catu*largura;
                      }
                      desenha=1;
                }
                if(desenha){
                  al_set_target_bitmap(newspr);
                  al_clear_to_color(al_map_rgb(0,0,0));
                  al_draw_bitmap_region(a,regiaox,0,largura,altura,0,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(newspr,150,300,0);
                }
                
                if(time==1){
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "O primeiro minigame e facil, basta rebater");
                al_draw_text(font2,al_map_rgb(255,255,255),250,35, ALLEGRO_ALIGN_CENTRE, "a bolinha que vira para seu lado, com seu");
                al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "quadrado, use W,S, para se mover, basta");
                al_draw_text(font2,al_map_rgb(255,255,255),250,85, ALLEGRO_ALIGN_CENTRE, "3 pontos para ganhar...");
                al_draw_text(font2,al_map_rgb(255,255,255),250,135, ALLEGRO_ALIGN_CENTRE, "O importante e vencer o minigame, para");
                al_draw_text(font2,al_map_rgb(255,255,255),250,160, ALLEGRO_ALIGN_CENTRE, "Conseguir uma dica sobre nossa noite");
                }
                if(time==2){
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Iremos enfrentar agora um campo minado");
                al_draw_text(font2,al_map_rgb(255,255,255),250,35, ALLEGRO_ALIGN_CENTRE, "a regra e simples clique nos quadrados");
                al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "e nao acerte a bomba, basta acabar os");
                al_draw_text(font2,al_map_rgb(255,255,255),250,85, ALLEGRO_ALIGN_CENTRE, "quadrados sem bomba para ganhar...");
                al_draw_text(font2,al_map_rgb(255,255,255),250,135, ALLEGRO_ALIGN_CENTRE, "O importante e vencer o minigame, para");
                al_draw_text(font2,al_map_rgb(255,255,255),250,160, ALLEGRO_ALIGN_CENTRE, "Conseguir uma dica sobre nossa noite");
                }
                if(time==3){
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Esse proximo jogo, quase todos conhecem");
                al_draw_text(font2,al_map_rgb(255,255,255),250,35, ALLEGRO_ALIGN_CENTRE, "e um simples jogo da velha, basta ter");
                al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "3 X seguidos, em diagonal ou horizontal");
                al_draw_text(font2,al_map_rgb(255,255,255),250,85, ALLEGRO_ALIGN_CENTRE, "ou vertical para ganhar...");
                al_draw_text(font2,al_map_rgb(255,255,255),250,135, ALLEGRO_ALIGN_CENTRE, "O importante e vencer o minigame, para");
                al_draw_text(font2,al_map_rgb(255,255,255),250,160, ALLEGRO_ALIGN_CENTRE, "Conseguir uma dica sobre nossa noite");
                }
                if(time==4){
                al_draw_text(font2,al_map_rgb(255,255,255),250,10, ALLEGRO_ALIGN_CENTRE, "Esse e o nosso ultimo minigame");
                al_draw_text(font2,al_map_rgb(255,255,255),250,35, ALLEGRO_ALIGN_CENTRE, "basta clicar na cor que representa a");
                al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "juncao das duas cores superiores");
                al_draw_text(font2,al_map_rgb(255,255,255),250,85, ALLEGRO_ALIGN_CENTRE, "faca 3 acertos para ganhar...");
                al_draw_text(font2,al_map_rgb(255,255,255),250,135, ALLEGRO_ALIGN_CENTRE, "O importante e vencer o minigame, para");
                al_draw_text(font2,al_map_rgb(255,255,255),250,160, ALLEGRO_ALIGN_CENTRE, "Conseguir uma dica sobre nossa noite");  
                }
                al_draw_text(font2,al_map_rgb(255,255,255),350,400, ALLEGRO_ALIGN_CENTRE, "Press Enter to play");
              al_flip_display();
            
                
        }
    
    }     
     void darDica(int choichoi,int time,int dica){
    ALLEGRO_BITMAP *a;
     al_clear_to_color(al_map_rgb(0,0,0));
     al_flip_display();
        if(choichoi==1){
            a= dance1;   
        }
        if(choichoi==2){
            a= dance2;   
        }
        if(choichoi==3){
            a= dance3;   
        }
        if(choichoi==4){
            a= dance4;   
        }
        if(choichoi==5){
            a= dance5;   
        }
        if(choichoi==6){
            a= dance6;
        }
        int colunas=7;
        int frames=10;
        int frameatu=0;
        int catu=0,regiaox=0;
        int largura=64,altura=64;
        int ex=0;
        int desenha;
        while(!ex){
                al_convert_mask_to_alpha(a,al_map_rgb(0,0,0));
                ALLEGRO_EVENT evento;
                al_wait_for_event(fila,&evento);
                
                
                if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                       destroir();
                  } 
                if(evento.type==ALLEGRO_EVENT_KEY_DOWN){
                    if(evento.keyboard.keycode==ALLEGRO_KEY_ENTER){
                        ex++;
                    }
                }
                if(evento.type==ALLEGRO_EVENT_TIMER){
                  
                      frameatu++;
                      if(frameatu >= frames){
                          frameatu=0;
                          catu++;
                          if(catu>= colunas){
                          catu=0;
                          }
                          regiaox=catu*largura;
                      }
                      desenha=1;
                }
                if(desenha){
                  al_set_target_bitmap(newspr);
                  al_clear_to_color(al_map_rgb(0,0,0));
                  al_draw_bitmap_region(a,regiaox,0,largura,altura,0,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(newspr,150,300,0);
                }
                if(dica){
                    if(time==1)
                    al_draw_text(font2,al_map_rgb(255,255,255),250,40, ALLEGRO_ALIGN_CENTRE, "Voce lembra-se de ter ido a um 'evento'");
                    if(time==2){
                    al_draw_text(font2,al_map_rgb(255,255,255),250,40, ALLEGRO_ALIGN_CENTRE, "Voce encontrou alguem,");
                    al_draw_text(font2,al_map_rgb(255,255,255),250,55, ALLEGRO_ALIGN_CENTRE, "Mas nao lembra quem...");
                    }
                    if(time==3){
                    al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "Seu amigo havia te convidado para");
                    al_draw_text(font2,al_map_rgb(255,255,255),250,55, ALLEGRO_ALIGN_CENTRE, "sair e te comprou uma substancia...");
                    }
                    if(time==4){
                        
                    }
                }
                else
                al_draw_text(font2,al_map_rgb(255,255,255),250,40, ALLEGRO_ALIGN_CENTRE, "Voce perdeu sem dica dessa vez");
                al_draw_text(font2,al_map_rgb(255,255,255),350,500, ALLEGRO_ALIGN_CENTRE, "Press Enter to Continue");
              al_flip_display();
            
                
        }
    
    }  
    void youwin(int s_n,int choichoi){
        ALLEGRO_BITMAP *a;
     al_clear_to_color(al_map_rgb(0,0,0));
     al_flip_display();
        if(choichoi==1){
            a= dance1;   
        }
        if(choichoi==2){
            a= dance2;   
        }
        if(choichoi==3){
            a= dance3;   
        }
        if(choichoi==4){
            a= dance4;   
        }
        if(choichoi==5){
            a= dance5;   
        }
        if(choichoi==6){
            a= dance6;
        }
        int colunas=7;
        int frames=10;
        int frameatu=0;
        int catu=0,regiaox=0;
        int largura=64,altura=64;
        int ex=0;
        int desenha;
        while(!ex){
                al_convert_mask_to_alpha(a,al_map_rgb(0,0,0));
                ALLEGRO_EVENT evento;
                al_wait_for_event(fila,&evento);
                
                
                if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
                       destroir();
                  } 
                if(evento.type==ALLEGRO_EVENT_KEY_DOWN){
                    if(evento.keyboard.keycode==ALLEGRO_KEY_ENTER){
                        ex++;
                    }
                }
                if(evento.type==ALLEGRO_EVENT_TIMER){
                  
                      frameatu++;
                      if(frameatu >= frames){
                          frameatu=0;
                          catu++;
                          if(catu>= colunas){
                          catu=0;
                          }
                          regiaox=catu*largura;
                      }
                      desenha=1;
                }
                if(desenha){
                  al_set_target_bitmap(newspr);
                  al_clear_to_color(al_map_rgb(0,0,0));
                  al_draw_bitmap_region(a,regiaox,0,largura,altura,0,0,0);
                  al_set_target_bitmap(al_get_backbuffer(display));
                  al_draw_bitmap(newspr,150,300,0);
                }
                if(s_n==1){
                al_draw_text(font2,al_map_rgb(255,255,255),250,45, ALLEGRO_ALIGN_CENTRE, "Voce acertou parabens");
                al_draw_text(font2,al_map_rgb(255,255,255),250,60, ALLEGRO_ALIGN_CENTRE, "seu assasino...");
                }
                else if(s_n==2){
                    al_draw_text(font2,al_map_rgb(255,255,255),250,40, ALLEGRO_ALIGN_CENTRE, "acho que nao foi bem isso");
               
                    }
                else{
                    al_draw_text(font2,al_map_rgb(255,255,255),250,40, ALLEGRO_ALIGN_CENTRE, "Voce passou perto");
                    }
                    al_draw_text(font2,al_map_rgb(255,255,255),350,500, ALLEGRO_ALIGN_CENTRE, "Press Enter to Ranking");
              al_flip_display();
            }
        
        }
     
int main()
{
    qu *v,*v1,*v2;
    int ex=0,resp[50];
    int perg[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int *resper,r_n,M_F;
    char *nome;
    int champ;
    int qualMinijafoi[4],qualmini;
    
    
    
    if(!iniciar()){
        al_destroy_display(display);
        return -1;
    }
    
    nome=Nome();
    int p=0;
    menu(nome);
    Male_Female(&M_F,nome);
    if(M_F)
    animarlixo(&champ);
    else if(!M_F)
    animardeVDD(&champ);
    al_rest(5);
    History(champ);
    
    
    printf("%s saiu\n",nome);
    v =  question();
    resper = answer();
    //printf("%s",v[0].q);
    int i=0,l,dica;
    while(!ex){
              if(i==7){
                    
                    intro(champ,1);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_flip_display();
                    minijojo1(&dica);
                    darDica(champ,1,dica);
                    
                    printf("saiu do minijoj1\n");
              }
              else if(i==15){
                    
                    intro(champ,2);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_flip_display();
                    minijojo2(&dica);
                    darDica(champ,2,dica);
              }
              else if(i==23){
                    
                    intro(champ,1);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_flip_display();
                    minijojo3(&dica);
                    darDica(champ,3,dica);
              }
              else if(i==31){
                    intro(champ,4);
                    al_clear_to_color(al_map_rgb(0,255,0));
                    al_flip_display();
                    minijojo4(&dica);
                    darDica(champ,1,dica);
              }
              else{
                  lvl(v,perg,&resp[i],&l,i,&r_n,p);
                  if(i==6||i==14||i==22||i==30){
                        ALLEGRO_BITMAP *nsei;
                        nsei=al_create_bitmap(200,40);
                        al_set_target_bitmap(nsei);
                        al_clear_to_color(al_map_rgb(0,255,0));
                        al_draw_text(font2,al_map_rgb(0,255,0),540,20, ALLEGRO_ALIGN_CENTRE, "Vai na Sorte");
                        al_set_target_bitmap(al_get_backbuffer(display));
                        al_draw_bitmap(nsei,340,20,0);
                        al_flip_display();
                        srand(time(NULL));
                        int port;
                        port=rand()%3;
                            if(port==0){
                                if(resp[i]==1){
                                    p=p+p/2;
                                }
                                if(resp[i]==2){
                                    p=p-p/2;
                                }
                                if(resp[i]==3){
                                    p=p;
                                }
                            }
                            if(port==1){
                                if(resp[i]==2){
                                    p=p+p/2;
                                }
                                if(resp[i]==1){
                                    p=p-p/2;
                                }
                                if(resp[i]==3){
                                    p=p;
                                }
                            }
                            if(port==2){
                                if(resp[i]==3){
                                    p=p+p/2;
                                }
                                if(resp[i]==2){
                                    p=p-p/2;
                                }
                                if(resp[i]==1){
                                    p=p;
                                }
                            }
                            if(port==3){
                                if(resp[i]==2){
                                    p=p+p/2;
                                }
                                if(resp[i]==3){
                                    p=p-p/2;
                                }
                                if(resp[i]==1){
                                    p=p;
                                }
                            }
                        }
                  else{
                      if(!r_n){
                          if(resp[i]!=resper[l]){
                                youwin(2,champ);
                                             ranking(nome,p);
                          }
                          else
                          p++;
                      }     
                      else{
                           if(resp[i]!=resp[l]){
                                youwin(2,champ);
                                               ranking(nome,p);
                           }
                           else
                           p++;
                      } 
                  }
              }             
              printf("%d\n%d\n%d\n",resp[i],resper[l],perg[i]);
              i++; 
              if(i==33){
              youwin(1,champ);
              ranking(nome,p);
                        
              }
    }
    free(nome);
    //printf("errou");
  //al_rest(3);
  destroir();
  // return 0;
}
