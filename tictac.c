#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h> //for randfunc seed

char grid[10];
int mve = 2;

main(){
int h;
char again[2];
do{       
   initzGrid();
   dispBoard();
      
  for(;;){
        
  makeMove(getMove());
  dispBoard();
  
  h = checkwin();
  
  if(h==2){
     printf("You win!!\n");
     break;
     }
  else if(h==1){
       printf("You lose! I win..\n");
       break;
       }
  else {
      printf("\nWe have draw..\n");
      break;
      }

 }//for loop end
printf("Try again? [Y/N] "); 
gets(again);
mve=2;
}while((again[0] == 'y')||(again[0] == 'Y'));

}//main end

initzGrid(){
   int i;
   for(i=0;i<=9;i++){
       grid[i] = ' ';
   }
   grid[5] = 'X';
   grid[0] = 'X';
}

dispBoard(){

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,194,196,196,196,194,196,196,196,191);
printf("%c %c %c %c %c %c %c\n",179,grid[1],179,grid[2],179,grid[3],179);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,180);
printf("%c %c %c %c %c %c %c\n",179,grid[4],179,grid[5],179,grid[6],179);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,180);
printf("%c %c %c %c %c %c %c\n",179,grid[7],179,grid[8],179,grid[9],179);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,193,196,196,196,193,196,196,196,217);

}

int getMove(){
    char x[5];
    int y=0;  
    
    do{
       do{
          printf("your move [1-9] : ");
          gets(x);
       }while(((x[0]=='\0')||(nonDigitFound(x)==1))&&(printf("Invalid move..\n")));
    y = atoi(x);
    }while((((y<=0)||(y>=10))||(grid[y]!=' '))&&(printf("Invalid move..\n")));
    
    grid[y] = 'O';
    dispBoard();
    return y;
}

int checkwin(){
    char a;
    if((grid[1]==grid[2])&&(grid[2]==grid[3])){
        a = grid[1];   
    }
    
    else if((grid[4]==grid[5])&&(grid[5]==grid[6])){
         a = grid[4];
    }
    
    else if((grid[7]==grid[8])&&(grid[8]==grid[9])){
        a = grid[7];
    }
    
    else if((grid[1]==grid[4])&&(grid[4]==grid[7])){
         a = grid[1];
    }
    
    else if((grid[2]==grid[5])&&(grid[5]==grid[8])){
         a = grid[2];
    }
    
    else if((grid[3]==grid[6])&&(grid[6]==grid[9])){
         a = grid[3];
    }
    
    else if((grid[1]==grid[5])&&(grid[5]==grid[9])){
         a = grid[1];
    }
    
    else if((grid[3]==grid[5])&&(grid[5]==grid[7])){
         a = grid[3];
    }
    else return 0;
    
    switch(a){
          
          case 'X': return 1;
          case 'O': return 2;
          default : return 0;
    }
    
}


int nonDigitFound(char x[]){
    int c; 
    for(c=0; x[c]!='\0'; c++){
       if((isalpha(x[c]))||(x[c]==' ')){
       return 1;
       break;
       }
    
    }
   return 0; 
}

makeMove(int i){
   switch(i){
          case 2: fork2();break;
          case 4: fork4();break;
          case 6: fork6();break;
          case 8: fork8();break;
          default: defMove();
   }
}

thinkPhrase(){
 printf("Nice move, my turn");
 int i =0;
 for(i=0;i<3;i++){putchar('.');Sleep(500);}
 putchar('\n');
}

//make move fork 2

fork2(){
for(;;){   
   thinkPhrase();
   grid[9] = 'X';
   dispBoard();
   
   if(getMove()==1){
      grid[3] = 'X';
      thinkPhrase();
      dispBoard();
   }
   else{
        grid[1] = 'X';
        thinkPhrase();
        break;
   }
   
   if(getMove()==6){
      grid[7]='X';
      thinkPhrase(); //new thinkphrase here
      break;
   }
   else{
        grid[6]='X';
        thinkPhrase(); //new thrash talk
        break;
   }
   
}
}

//fork4 move

fork4(){
for(;;){   
   thinkPhrase();
   grid[9] = 'X';
   dispBoard();
   
   if(getMove()==1){
      grid[7] = 'X';
      thinkPhrase();
      dispBoard();
   }
   else{
        grid[1] = 'X';
        thinkPhrase();
        break;
   }
   
   if(getMove()==8){
      grid[3]='X';
      thinkPhrase(); //new thinkphrase here
      break;
   }
   else{
        grid[8]='X';
        thinkPhrase(); //new thrash talk
        break;
   }
   
}
}

//fork 6
fork6(){
for(;;){   
   thinkPhrase();
   grid[1] = 'X';
   dispBoard();
   
   if(getMove()==9){
      grid[3] = 'X';
      thinkPhrase();
      dispBoard();
   }
   else{
        grid[9] = 'X';
        thinkPhrase();
        break;
   }
   
   if(getMove()==2){
      grid[7]='X';
      thinkPhrase(); //new thinkphrase here
      break;
   }
   else{
        grid[2]='X';
        thinkPhrase(); //new thrash talk
        break;
   }
   
}
}

//fork 8
fork8(){
for(;;){   
   thinkPhrase();
   grid[1] = 'X';
   dispBoard();
   
   if(getMove()==9){
      grid[7] = 'X';
      thinkPhrase();
      dispBoard();
   }
   else{
        grid[9] = 'X';
        thinkPhrase();
        break;
   }
   
   if(getMove()==3){
      grid[4]='X';
      thinkPhrase(); //new thinkphrase here
      break;
   }
   else{
        grid[3]='X';
        thinkPhrase(); //new thrash talk
        break;
   }
   
}
}

randMove(){
mve++;
int r = 0;

srand ( time(NULL) );
do{
   do{
        
        r = rand() % 10;
        if(mve>5)break;
        
   }while((r==0)||(r==5)||((r%2)==0));
   
   if((grid[r]==' ')&&(r!=0)){
      grid[r]='X';
      thinkPhrase();
      dispBoard();
      
      break;
   }
}while(grid[r]!=' ');
}

defMove(){

randMove();
do{
    
    getMove();
    
    int c = canwin();
    
    if(c==1){thinkPhrase();break;} 
    else if(c==2){thinkPhrase();dispBoard();mve++;}
    else if(c==0)randMove();     
    
}while(gridFull()==0);
}

int gridFull(){
    int i,j;
    for(i=1;i<=9;i++){
       if(grid[i]==' '){
       return 0;
       }
       
    }
   return 1;
}


int canwin(){
   int i;
   for(i=1;i<=9;i++){
       if(grid[i]==' '){
          
          grid[i] = 'X';
          if(checkwin()==1){
             return 1;
             
          }
          else{ 
             grid[i] = ' ';
             
          }          
         grid[i] = ' ';  
       }//if clause space checker end
   }
   
   for(i=1;i<=9;i++){
       if(grid[i]==' '){
       grid[i] = 'O';
          if(checkwin()==2){
             grid[i] = 'X';
             return 2;
             break;
            }
          else{
               grid[i] = ' ';       
               }
          grid[i] = ' ';
       }
                     
   }//for loop end
   return 0; 
}//canwin end
