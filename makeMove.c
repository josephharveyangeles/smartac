#include<stdio.h>
#include<windows.h>



makeMove(int i){
   switch(i){
          case 2: fork2();break;
   }
}

thinkPhrase(){
 printf("Nice move, my turn");
 int i =0;
 for(i=0;i<3;i++){putchar('.');Sleep(500);}
 putchar('\n');
}

fork2(){
for(;;){   
   thinkPhrase();
   grid[9] = 'X';
   dispBoard();
   
   if(getMove()==1){
      grid[3] == 'X';
      thinkPhrase();
      dispBoard();
   }
   else{
        grid[1] == 'X';
        thinkPhrase();
        break;
   }
   
   if(getMove()==6){
      grid[7]=='X';
      thinkPhrase(); //new thinkphrase here
      break;
   }
   else{
        grid[6]=='X';
        thinkPhrase(); //new thrash talk
        break;
   }
   
}
}
