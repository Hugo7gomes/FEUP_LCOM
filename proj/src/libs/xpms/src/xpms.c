#include <lcom/lcf.h>
#include "xpms.h"

char* mapXpms[63];


char * mouse[] = {
"16 19 3",
". 0",
"x 63",
"c 3",
"c...............",
"cc..............",
"cxc.............",
"cxxc............",
"cxxxc...........",
"cxxxxc..........",
"cxxxxxc.........",
"cxxxxxxc........",
"cxxxxxxxc.......",
"cxxxxxxxxc......",
"cxxxxxxxxxc.....",
"cxxxxxxxxxxc....",
"cxxxxxxccccc....",
"cxxxcxxc........",
"cxxc.cxxc.......",
"cxc..cxxc.......",
"cc....cxxc......",
"......cxxc......",
".......cc......."
};


char *A[] = {
"20 15 2",
". 0",
"x 2",
"........xxxxx.......",               
".......xxxxxxx......",              
"......xxxxxxxxx.....",             
".....xxxxxxxxxxx....",            
"....xxxxxxxxxxxxx...",           
"...xxxxxxx.xxxxxxx..",          
"..xxxxxxx...xxxxxxx.",         
".xxxxxxx.....xxxxxxx",            
".xxxxxxxxxxxxxxxxxxx",      
".xxxxxxxxxxxxxxxxxxx",     
".xxxxxxxxxxxxxxxxxxx",    
".xxxxx.........xxxxx",   
".xxxxx.........xxxxx",  
".xxxxx.........xxxxx", 
".xxxxx.........xxxxx"
};

char *B[] = {
"20 15 2",
". 0",
"x 2",
"..xxxxxxxxxxxxxxx...",   
"..xxxxxxxxxxxxxxxx..", 
"..xxxxxxxxxxxxxxxxx.", 
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxxxxxxxxxxxxx.",
"..xxxxxxxxxxxxxxxx..",  
"..xxxxxxxxxxxxxxxxx.",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxx.",
"..xxxxxxxxxxxxxxxx.."    
};

char *C[] = {
"20 15 2",
". 0",
"x 2",
".........xxxxxxxxxxx",
"......xxxxxxxxxxxxxx",
"....xxxxxxxxxxxxxxxx",
"...xxxxxxxxxxxxxxxxx",
"..xxxxxxx...........",
".xxxxxxx............",
".xxxxxxx............",
".xxxxxxx............",      
".xxxxxxx............", 
".xxxxxxx............", 
"..xxxxxxx...........",
"...xxxxxxxxxxxxxxxxx",
"....xxxxxxxxxxxxxxxx",
"......xxxxxxxxxxxxxx",
".........xxxxxxxxxxx"
};

char *D[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxxxxx.........",
".xxxxxxxxxxxxx......",    
".xxxxxxxxxxxxxxx....",  
".xxxxxxxxxxxxxxxx...", 
".xxxxx.....xxxxxxx..",
".xxxxx......xxxxxxx.",
".xxxxx......xxxxxxx.",
".xxxxx......xxxxxxx.",
".xxxxx......xxxxxxx.",
".xxxxx......xxxxxxx.",
".xxxxx.....xxxxxxx..",
".xxxxxxxxxxxxxxxx...",  
".xxxxxxxxxxxxxxx....",
".xxxxxxxxxxxxx......",
".xxxxxxxxxxxx......."
};

char *E[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxxxxxxxxxxxxxx", 
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxx.............",
".xxxxxx.............",
".xxxxxxxxxxxxxxxx...",
".xxxxxxxxxxxxxxxx...",
".xxxxxxxxxxxxxxxx...",
".xxxxxx.............",
".xxxxxx.............",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx"
};
                      
char *F[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxx.............",
".xxxxxx.............",            
".xxxxxxxxxxxxxxxx...",   
".xxxxxxxxxxxxxxxx...",     
".xxxxxxxxxxxxxxxx...",   
".xxxxxx.............",             
".xxxxxx.............",             
".xxxxxx.............",           
".xxxxxx.............",           
".xxxxxx.............",           
".xxxxxx............."
};

char *G[] = {
"20 15 2",
". 0",
"x 2",
".......xxxxxxxxxxxxx",
".....xxxxxxxxxxxxxxx",
"...xxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
".xxxxxxx............",      
".xxxxxxx............",              
".xxxxxxx............",              
".xxxxxxx....xxxxxxxx",
".xxxxxxx....xxxxxxxx",
".xxxxxxx....xxxxxxxx",
".xxxxxxx........xxxx",
".xxxxxxx........xxxx",
"..xxxxxxxxxxxxxxxxxx",
"...xxxxxxxxxxxxxxxxx",
".....xxxxxxxxxxxxxxx"
};


char *H[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",  
".xxxxxxx.....xxxxxxx",  
".xxxxxxxxxxxxxxxxxxx",  
".xxxxxxxxxxxxxxxxxxx", 
".xxxxxxxxxxxxxxxxxxx",   
".xxxxxxxxxxxxxxxxxxx",  
".xxxxxxxxxxxxxxxxxxx",  
".xxxxxxx.....xxxxxxx",  
".xxxxxxx.....xxxxxxx", 
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx"
};

char *I[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".......xxxxxxx......",
".......xxxxxxx......", 
".......xxxxxxx......", 
".......xxxxxxx......", 
".......xxxxxxx......",    
".......xxxxxxx......",   
".......xxxxxxx......",   
".......xxxxxxx......",  
".......xxxxxxx......",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx"
};

char *J[] = {
"20 15 2",
". 0",
"x 2",
"............xxxxxxx.",
"............xxxxxxx.",
"............xxxxxxx.",
"............xxxxxxx.", 
"............xxxxxxx.",  
"............xxxxxxx.", 
"............xxxxxxx.",  
"............xxxxxxx.",  
".xxxxxxx....xxxxxxx.",  
".xxxxxxx....xxxxxxx.",  
".xxxxxxx...xxxxxxxx.",  
".xxxxxxxxxxxxxxxxxx.",  
".xxxxxxxxxxxxxxxxx..",   
"...xxxxxxxxxxxxx....",     
".....xxxxxxxxx......"   
};

char *K[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxx.......xxxxxx",
".xxxxxx......xxxxxxx",
".xxxxxx.....xxxxxxx.",
".xxxxxx....xxxxxxx..",
".xxxxxx...xxxxxxx...",   
".xxxxxxxxxxxxxx.....",    
".xxxxxxxxxxxxx......",     
".xxxxxxxxxxxxx......",     
".xxxxxxxxxxxxxx.....",    
".xxxxxx...xxxxxx....",  
".xxxxxx....xxxxxx...",
".xxxxxx.....xxxxxx..",
".xxxxxx......xxxxxx.",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx"
};

char *L[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxx............",             
".xxxxxxx............",                         
".xxxxxxx............",             
".xxxxxxx............",               
".xxxxxxx............",               
".xxxxxxx............",               
".xxxxxxx............",               
".xxxxxxx............",               
".xxxxxxx............",               
".xxxxxxx............",               
".xxxxxxx............",         
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx"
};

char *M[] = {
"20 15 2",
". 0",
"x 2",                               
".xxxxx.........xxxxx",
".xxxxxx.......xxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxx...xxxxxxxx",
".xxxxxxxxx.xxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxx..xxx..xxxxxx",
".xxxxxx...x...xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx"
};
  
char *N[] = {
"20 15 2",
". 0",
"x 2",                        
".xxxxx.........xxxxx",
".xxxxxx........xxxxx",
".xxxxxxx.......xxxxx",
".xxxxxxxx......xxxxx",
".xxxxxxxxx.....xxxxx",
".xxxxxxxxxx....xxxxx",
".xxxxxxxxxxx...xxxxx",
".xxxxx.xxxxxx..xxxxx",
".xxxxx..xxxxxx.xxxxx",
".xxxxx...xxxxxxxxxxx",
".xxxxx....xxxxxxxxxx",
".xxxxx.....xxxxxxxxx",
".xxxxx......xxxxxxxx",
".xxxxx.......xxxxxxx",
".xxxxx........xxxxxx"
};

char *O[] = {
"20 15 2",
". 0",
"x 2",
"......xxxxxxxxx.....",
"....xxxxxxxxxxxxx...",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxx...xxxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxx...xxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxx.",
"....xxxxxxxxxxxxx...",
"......xxxxxxxxx....."
};

char *P[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxxxxxxxxxxx...",   
".xxxxxxxxxxxxxxxxx..", 
".xxxxxxxxxxxxxxxxxx.",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxx..",
".xxxxxxxxxxxxxxx....", 
".xxxxxxx............",
".xxxxxxx............",           
".xxxxxxx............",            
".xxxxxxx............",         
".xxxxxxx............",          
".xxxxxxx............"    
};

char *Q[] = {
"20 15 2",
". 0",
"x 2",                   
"......xxxxxxxx......", 
"....xxxxxxxxxxxx....", 
"..xxxxxxxxxxxxxxxx..", 
".xxxxxxxxxxxxxxxxxx.", 
".xxxxxxxx..xxxxxxxx.", 
".xxxxxxx....xxxxxxx.", 
".xxxxxxx....xxxxxxx.", 
".xxxxxxx....xxxxxxx.", 
".xxxxxxx....xxxxxxx.", 
".xxxxxxxx..xxxxxxxx.", 
".xxxxxxxxxxxxxxxxxx.", 
"..xxxxxxxxxxxxxxxx..", 
"...xxxxxxxxxxxxx....",
"......xxxxxxxxxxxxx.",
".............xxxxxxx"
};

char *R[] = {
"20 15 2",
". 0",
"x 2",
"..xxxxxxxxxxxxxxx...",
"..xxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxxx.",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxxxxxxxxxxxxx.",
"..xxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxxx.",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx",
"..xxxxxx.....xxxxxxx"
};

char *S[] = {
"20 15 2",
". 0",
"x 2",
"...xxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxx......xxxxxxx",
".xxxxxx.............",
".xxxxxxxxx..........",
"..xxxxxxxxxxxxxx....",      
".....xxxxxxxxxxxxx..",
"........xxxxxxxxxxx.",
".............xxxxxxx",
".............xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxx.",
"..xxxxxxxxxxxxxxx..."
};

char *T[] = {
"20 15 2",
". 0",
"x 2",
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
".......xxxxxx.......",        
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......", 
".......xxxxxx......."
};


char *U[] = {
"20 15 2",
". 0",
"x 2",                     
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxx.",
"...xxxxxxxxxxxxxx...", 
".....xxxxxxxxxx....."
};

char *V[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxxx.....xxxxxxx",
"..xxxxxxx...xxxxxxx.",
"...xxxxxxx.xxxxxxx..",
"....xxxxxxxxxxxxx...",
".....xxxxxxxxxxx....",
"......xxxxxxxxx.....",
".......xxxxxxx......",
"........xxxxx......."
};
                                           
char *W[] = {
"20 15 2",
". 0",
"x 2",                                         
".xxxxx.........xxxxx",
".xxxxx.........xxxxx",
".xxxxx.........xxxxx",
".xxxxx.........xxxxx",
".xxxxx.........xxxxx",
".xxxxx.........xxxxx",  
".xxxxx...xxx...xxxxx",   
".xxxxx..xxxxx..xxxxx",    
".xxxxx.xxxxxxx.xxxxx",     
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",            
".xxxxxxxxx.xxxxxxxxx",       
"..xxxxxxx...xxxxxxx.",        
"...xxxxx.....xxxxx..",         
"....xxx.......xxx..."   
};

char *X[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
"..xxxxx.......xxxxx.",
"...xxxxx.....xxxxx..",
"....xxxxx...xxxxx...",
".....xxxxxxxxxxx....",
".....xxxxxxxxxxx....",
".....xxxxxxxxxxx....",
".....xxxxxxxxxxxx...", 
"....xxxxxx.xxxxxx...",
"...xxxxxx...xxxxxx..",
"..xxxxxx.....xxxxxx.",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx",
".xxxxxx.......xxxxxx"
};

char *Y[] = {
"20 15 2",
". 0",
"x 2",
".xxxxx.........xxxxx",
".xxxxxx.......xxxxxx",
".xxxxxxx.....xxxxxxx",
"..xxxxxxx...xxxxxxx.",
"...xxxxxxx.xxxxxxx..",
"....xxxxxxxxxxxxx...",
".....xxxxxxxxxxx....",
"......xxxxxxxxx.....",
".......xxxxxxx......",  
"........xxxxx.......", 
"........xxxxx.......",
"........xxxxx.......",
"........xxxxx.......",    
"........xxxxx.......",    
"........xxxxx......."       
};

char *Z[] = {
"20 15 2",
". 0",
"x 2",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".........xxxxxxxxxx.", 
"........xxxxxxxxxx..",  
".......xxxxxxxxxx...",    
"......xxxxxxxxxx....",     
".....xxxxxxxxxx.....",      
"....xxxxxxxxxx......",        
"...xxxxxxxxxx.......",         
"..xxxxxxxxxx........",     
".xxxxxxxxxx.........",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
};

char *a[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"..xxxxxxxxxxxxxxx...",
"..xxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxxx.",
"...........xxxxxxxx.",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxxx.",
".xxxxxx....xxxxxxxx.",
".xxxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxx..xxxxx"
};

char *b[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
".xxxxxxx............",
".xxxxxxx............",
".xxxxxxx............",   
".xxxxxxx............",
".xxxxxxx............",
".xxxxxxx............",
".xxxxxxxxxxxxxxxx...",
".xxxxxxxxxxxxxxxxxx.",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxx...",
".xxxxxxxxxxxxxxx...."
};

char *c[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"...xxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxx...........",
".xxxxxxx............",
".xxxxxxx............",
".xxxxxxxx...........",
".xxxxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
"....xxxxxxxxxxxxxxxx"
};

char *d[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
".............xxxxxxx",
".............xxxxxxx",
".............xxxxxxx",
".............xxxxxxx",
".............xxxxxxx",
".............xxxxxxx", 
"....xxxxxxxxxxxxxxxx", 
"..xxxxxxxxxxxxxxxxxx", 
".xxxxxxxxxxxxxxxxxxx", 
".xxxxxxx.....xxxxxxx", 
".xxxxxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
"....xxxxxxxxx...xxxx"
};

char *e[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"....xxxxxxxxxxxx....",    
"..xxxxxxxxxxxxxxxx..",  
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxxxxxxxxxxxxx.", 
".xxxxxxxxxxxxxxxxx..",  
".xxxxxxxx...........",     
".xxxxxxxxxxxxxxxxx..",  
"..xxxxxxxxxxxxxxxx..",  
"...xxxxxxxxxxxxxxx.."
};

char *f[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....xxxxxxxxxxxxxxx.",  
"...xxxxxxxxxxxxxxxxx", 
"..xxxxxxxxxxxxxxxxxx",
"..xxxxxxx......xxxxx",
"..xxxxxxx...........",   
".xxxxxxxxxxxxxx.....",   
".xxxxxxxxxxxxxx.....",   
".xxxxxxxxxxxxxx.....",   
"..xxxxxxx...........",   
"..xxxxxxx...........",   
"..xxxxxxx...........",       
"..xxxxxxx..........."  
};


char *g[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....xxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxx....xxxxxxx", 
".xxxxxxxxxxxxxxxxxxx", 
"...xxxxxxxxxxxxxxxxx", 
".....xxxxxxxxxxxxxxx", 
".............xxxxxxx", 
".xxxxxx......xxxxxxx", 
".xxxxxxxx...xxxxxxxx", 
"..xxxxxxxxxxxxxxxxxx", 
"....xxxxxxxxxxxx....",
".......xxxxxx......."
};

char *lh[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",             
".xxxxxx.............",             
".xxxxxx.............",             
".xxxxxx.............",
".xxxxxx.............",       
".xxxxxx.xxxxxxxx....",    
".xxxxxxxxxxxxxxxx...",  
".xxxxxxxxxxxxxxxxxx.", 
".xxxxxxx....xxxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx"
};


char *i[] = {
"20 15 2",
". 0",
"x 2",
"........xxxx........",  
".......xxxxxx.......", 
"........xxxx........",  
"....................",        
"......xxxxxxxx......", 
"......xxxxxxxx......", 
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......",
"......xxxxxxxx......"
};

char *j[] = {
"20 15 2",
". 0",
"x 2",                  
"..............xxxx..", 
".............xxxxxx.",
"..............xxxx..", 
"....................",
"...........xxxxxxx..",
"...........xxxxxxx..",
"............xxxxxx..",
"............xxxxxx..",
"............xxxxxx..",
"............xxxxxx..",
"............xxxxxx..",
"..xxxx......xxxxxx..",
".xxxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxx...",
".....xxxxxxxxxx....."
};

char *k[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
".xxxxxx....xxxxxxx..",
".xxxxxx...xxxxxxx...", 
".xxxxxx..xxxxxxx....",  
".xxxxxx.xxxxxxx.....",   
".xxxxxxxxxxxxx......",    
".xxxxxxxxxxxx.......",    
".xxxxxxxxxxxx.......",    
".xxxxxxxxxxxxx......",    
".xxxxxx.xxxxxxx.....",   
".xxxxxx..xxxxxxx....",  
".xxxxxx...xxxxxxx..."  
};

char *l[] = {
"20 15 2",
". 0",
"x 2",
".......xxxxxx.......", 
".......xxxxxx.......",
".......xxxxxx.......", 
".......xxxxxx.......", 
".......xxxxxx.......",
".......xxxxxx.......", 
".......xxxxxx.......", 
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx......."
};

char *m[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx"
};                        

char *n[] = {
"20 15 2",
". 0",
"x 2",               
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxxxxxxxxxxxxxx...", 
".xxxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxx..",
"..xxxxxx....xxxxxx..",
"..xxxxxx....xxxxxx..",
"..xxxxxx....xxxxxx..",
"..xxxxxx....xxxxxx..",
"..xxxxxx....xxxxxx..",
"..xxxxxx....xxxxxx..",
"..xxxxxx....xxxxxx.."
};

char *o[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"....xxxxxxxxxxxx....",   
"..xxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxx......xxxxxx.",
".xxxxxx......xxxxxx.",
".xxxxxx......xxxxxx.",
".xxxxxx......xxxxxx.",
".xxxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxx..",
"....xxxxxxxxxxxx...."
};

char *p[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
".xxxxxxxxxxxxxxxx...",   
".xxxxxxxxxxxxxxxxx..", 
".xxxxxxxxxxxxxxxxxx.",
".xxxxxx....xxxxxxxx.",
".xxxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxx..", 
".xxxxxxxxxxxxxxxx...",    
".xxxxxx.............",       
".xxxxxx.............",    
".xxxxxx.............",                 
".xxxxxx............."       
};


char *q[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....xxxxxxxxxxxxxxxx",
"..xxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxx.....xxxxxxx", 
".xxxxxxxxxxxxxxxxxxx", 
"..xxxxxxxxxxxxxxxxxx", 
"...xxxxxxxxxxxxxxxxx", 
".............xxxxxxx", 
".............xxxxxxx", 
".............xxxxxxx",
".............xxxxxxx"
};

char *r[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxx...xxxxxxxxx...",   
".xxxxxxxxxxxxxxxxx..",  
".xxxxxxxxxxxxxxxxxx.", 
".xxxxxxxxxxxxxxxxxx.",
".xxxxxx......xxxxxx.",
".xxxxxx......xxxxxx.",
".xxxxxx.............",           
".xxxxxx.............",            
".xxxxxx.............",            
".xxxxxx............."     
};

char *s[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"...xxxxxxxxxxxxx....",   
".xxxxxxxxxxxxxxxx...", 
".xxxxxxxxxxxxxxxxx..",
"..xxxxxxx..xxxxxx...", 
"...xxxxxxxx.........",      
".......xxxxxxx......",   
".xxxxxx...xxxxxxx...", 
".xxxxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxx....",  
"...xxxxxxxxxxx......"    
};                  

                       
char *t[] = {
"20 15 2",
". 0",
"x 2",                       
"....................",
"....................",
".....xxxxxxx........",       
".....xxxxxxx........",          
".....xxxxxxx........",          
".....xxxxxxx........",          
".xxxxxxxxxxxxxxxxxxx",      
".xxxxxxxxxxxxxxxxxxx",    
".....xxxxxx.........",          
".....xxxxxx.........",          
".....xxxxxx.........",          
".....xxxxxx.....xxxx",
".....xxxxxxxxxxxxxxx",
"......xxxxxxxxxxxxxx",
".......xxxxxxxxxxxx."  
};

char *u[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxxxx....xxxxxx...",  
".xxxxxx....xxxxxx...",  
".xxxxxx....xxxxxx...",  
".xxxxxx....xxxxxx...",  
".xxxxxx....xxxxxx...",  
".xxxxxx....xxxxxx...",  
".xxxxxxxxxxxxxxxx...",  
".xxxxxxxxxxxxxxxxxx.",
"..xxxxxxxxxxxxxxxxxx",
"....xxxxxxxx..xxxxxx"
};

char *v[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxxx.........xxxxx",
".xxxxxx.......xxxxxx",  
"..xxxxxx.....xxxxxx.",   
"...xxxxxx...xxxxxx..",    
"....xxxxxx.xxxxxx...",     
".....xxxxxxxxxxx....",      
"......xxxxxxxxx.....",       
".......xxxxxxx......",          
"........xxxxx.......",          
".........xxx........"       
};

char *lw[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxx...xxxxx...xxxx",
".xxxx...xxxxx...xxxx", 
".xxxx...xxxxx...xxxx",   
".xxxx...xxxxx...xxxx",    
".xxxx...xxxxx...xxxx",     
".xxxxx.xxxxxxx.xxxxx",      
".xxxxxxxxxxxxxxxxxxx",       
".xxxxxxxx...xxxxxxxx",         
".xxxxxxx.....xxxxxxx",          
"..xxxxx.......xxxxx."           
};

char *x[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxxxxx.....xxxxxxx",
"..xxxxxxx...xxxxxxx.", 
"...xxxxxxx.xxxxxxx..",  
"....xxxxxxxxxxxxx...",   
".....xxxxxxxxxxx....",    
".....xxxxxxxxxxx....",
"....xxxxxxxxxxxxx...",
"...xxxxxxx.xxxxxxx..",
"..xxxxxxx...xxxxxxx.",
".xxxxxxx.....xxxxxxx"
};

char *y[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",                  
".xxxxxx.......xxxxxx",
"..xxxxxx.....xxxxxx.",    
"...xxxxxx...xxxxxx..",     
"....xxxxxx.xxxxxx...",      
".....xxxxxxxxxxx....",        
".......xxxxxxxx.....",         
".......xxxxxxx......",          
"......xxxxxxx.......",          
".....xxxxxxx........",          
"....xxxxxxx........."                 
};                     

char *z[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx", 
".xxxxxxxxxxxxxxxxxxx",  
".........xxxxxxxxxx.",   
".......xxxxxxxxx....",    
".....xxxxxxxxx......",     
"...xxxxxxxxx........",      
"..xxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx"
};


char *n1[] = {
"20 15 2",
". 0",
"x 2",
"....xxxxxxxxxx......",                
"....xxxxxxxxxx......",                
"....xxxxxxxxxx......",                
"....xxxxxxxxxx......",                
"......xxxxxxxx......",                
"......xxxxxxxx......",                
"......xxxxxxxx......",                
"......xxxxxxxx......",                
"......xxxxxxxx......",                
"......xxxxxxxx......",                
"......xxxxxxxx......",               
"......xxxxxxxx......",                
"....xxxxxxxxxxxx....",                 
"....xxxxxxxxxxxx....",             
"....xxxxxxxxxxxx...."             
};                                             
                         
                         
                                                  
char *n2[] = {
"20 15 2",
". 0",
"x 2",                         
"..xxxxxxxxxxxxxxx...",         
".xxxxxxxxxxxxxxxxxx.",       
".xxxxxxxxxxxxxxxxxxx",      
".xxxxxxx.....xxxxxxx",      
"............xxxxxxx.",          
".........xxxxxxxxx..",       
"....xxxxxxxxxxxxx...",        
"..xxxxxxxxxxxxx.....",          
".xxxxxxxxxxx........",             
".xxxxxxx............",                 
".xxxxxxx............",                 
".xxxxxxx......xxxxxx",     
".xxxxxxxxxxxxxxxxxxx",     
".xxxxxxxxxxxxxxxxxxx",     
".xxxxxxxxxxxxxxxxxxx"     
};                        
                         
                                             
char *n3[] = {
"20 15 2",
". 0",
"x 2",                         
"..xxxxxxxxxxxxxxxx..",     
".xxxxxxxxxxxxxxxxxx.",      
".xxxxxxxxxxxxxxxxxxx",      
".xxxxxx.....xxxxxxxx",      
"............xxxxxxxx",      
"............xxxxxxxx",      
".....xxxxxxxxxxxxxx.",       
".....xxxxxxxxxxxxx..",        
".....xxxxxxxxxxxxxx.",       
"............xxxxxxxx",      
"............xxxxxxxx",     
".xxxxxx.....xxxxxxxx",  
".xxxxxxxxxxxxxxxxxxx",   
".xxxxxxxxxxxxxxxxxx.",   
"..xxxxxxxxxxxxxxxx.."     
};                         
                         
char *n4[] = {
"20 15 2",
". 0",
"x 2",                            
"........xxxxxxxxx...",         
".......xxxxxxxxxx...",                 
"......xxxxxxxxxxx...",         
".....xxxxxxxxxxxx...",         
"....xxxxxx..xxxxx...",         
"...xxxxxx...xxxxx...",         
"..xxxxxx....xxxxx...",         
".xxxxxxxxxxxxxxxxxxx",       
".xxxxxxxxxxxxxxxxxxx",      
".xxxxxxxxxxxxxxxxxxx",       
"............xxxxx...",         
"............xxxxx...",         
"............xxxxx...",         
"............xxxxx...",         
"............xxxxx..."             
};                         
                         
                                   
char *n5[] = {
"20 15 2",
". 0",
"x 2",                          
".xxxxxxxxxxxxxxxxxxx",       
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",   
".xxxxxxx............",
".xxxxxxx............",                 
".xxxxxxxxxxxxxxxxx..",         
".xxxxxxxxxxxxxxxxxx.",        
".xxxxxxxxxxxxxxxxxxx",       
"...........xxxxxxxxx",      
"...........xxxxxxxxx",      
".xxxxxx....xxxxxxxxx",      
".xxxxxxxxxxxxxxxxxx.",      
".xxxxxxxxxxxxxxxxx..",       
"..xxxxxxxxxxxxxxx...",         
"....xxxxxxxxxxx....."                  
};
  
char *n6[] = {
"20 15 2",
". 0",
"x 2",                    
"........xxxxxxxx....",     
".......xxxxxxxx.....",      
"......xxxxxxxx......",       
".....xxxxxxxx.......",        
"....xxxxxxxx........",         
"...xxxxxxxx.........",          
"..xxxxxxxxxxxxxxx...",     
".xxxxxxxxxxxxxxxxx..",   
".xxxxxxxxxxxxxxxxxx.",  
".xxxxxx......xxxxxxx", 
".xxxxxx......xxxxxxx", 
".xxxxxxxxxxxxxxxxxx.", 
".xxxxxxxxxxxxxxxxx..",  
"..xxxxxxxxxxxxxx....",    
"....xxxxxxxxxxx....."      
};                    
                    
                         
char *n7[] = {
"20 15 2",
". 0",
"x 2",                    
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
"............xxxxxxxx", 
"...........xxxxxxxx.",
"..........xxxxxxxx..",
".........xxxxxxxx...", 
"........xxxxxxxx....",
".......xxxxxxxx.....",
"......xxxxxxxx......",
".....xxxxxxxx.......",
"....xxxxxxxx........",
"...xxxxxxxx.........",         
"..xxxxxxxx..........",          
".xxxxxxxx..........."           
};
                    
char *n8[] = {
"20 15 2",
". 0",
"x 2",                    
"......xxxxxxxxx.....",      
"....xxxxxxxxxxxxx...",    
"...xxxxxxxxxxxxxxx..",
".xxxxxxxxxxxxxxxxxxx", 
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx",
"..xxxxxxxxxxxxxxxxx.",  
"...xxxxxxxxxxxxxxx..",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx", 
".xxxxxxx.....xxxxxxx",
".xxxxxxxxxxxxxxxxxxx",
"...xxxxxxxxxxxxxxx..",
"......xxxxxxxxx....." 
};                   

char *n9[] = {
"20 15 2",
". 0",
"x 2",                    
"......xxxxxxxxx.....",      
"....xxxxxxxxxxxxx...",
"..xxxxxxxxxxxxxxxxx.",
".xxxxxxxxxxxxxxxxxxx", 
".xxxxxxx.....xxxxxxx",
".xxxxxxx.....xxxxxxx", 
"..xxxxxxxxxxxxxxxxx.",
"...xxxxxxxxxxxxxxxx.", 
"....xxxxxxxxxxxxxx..",  
"..........xxxxxxx...",   
".........xxxxxxx....",    
"........xxxxxxx.....",     
".......xxxxxxx......",      
"......xxxxxxx.......",       
".....xxxxxxx........"             
};                            
                    
                    
char *n0[] = {
"20 15 2",
". 0",
"x 2",                    
".....xxxxxxxxxx.....",      
"...xxxxxxxxxxxxxx...",    
".xxxxxxxxxxxxxxxxxx.",
"xxxxxxxxx..xxxxxxxxx", 
"xxxxxxxx....xxxxxxxx",
"xxxxxxx......xxxxxxx", 
"xxxxxxx......xxxxxxx",
"xxxxxxx......xxxxxxx",
"xxxxxxx......xxxxxxx",
"xxxxxxx......xxxxxxx",
"xxxxxxxx....xxxxxxxx",
"xxxxxxxxx..xxxxxxxxx", 
".xxxxxxxxxxxxxxxxxx.",  
"...xxxxxxxxxxxxxx...",  
".....xxxxxxxxxx....."
};

char *esp[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"...................."
};


char *p_int[] = {
"20 15 2",
". 0",
"x 2",
"....xxxxxxxx........",            
"..xxxxxxxxxxxx......",           
" xxxxxxxxxxxxxx.....",          
"xxxxxxxxxxxxxxxx....",              
"xxxxxx....xxxxxx....",        
".........xxxxxx.....",         
"........xxxxxx......",           
".......xxxxxx.......",            
"......xxxxxx........",              
"......xxxxxx........",             
".......xxxx.........",              
"....................",                         
".......xxx..........",               
"......xxxxx.........",              
".......xxx.........."   
};


char *p_exc[] = {
"20 15 2",
". 0",
"x 2",
"........xxx.........",                      
".......xxxxx........",                     
".......xxxxx........",                     
".......xxxxx........",                     
".......xxxxx........",                     
".......xxxxx........",                           
".......xxxxx........",                     
".......xxxxx........",                     
".......xxxxx........",                     
".......xxxxx........",                     
"........xxx.........",                      
"....................",                          
"........xxx.........",                      
".......xxxxx........",                     
"........xxx........."    
};


char *p_ponto[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",                
"....................",
"....................",
"....................",
"....................",
"....................",                     
"....................",                      
"....................",                          
".......xxxxxx.......",                      
".......xxxxxx.......",                     
".......xxxxxx......."    
};


char *p_virg[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",                
"....................",
"....................",
"....................",
"....................",
"....................",                     
".......xxxxxx.......",                     
".......xxxxxx.......",                          
".......xxxxxx.......",                      
".......xxx..........",                     
".......x............"    
};


char *p_2p[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
".......xxxxxx.......",                
".......xxxxxx.......",                      
".......xxxxxx.......",                     
"....................",
"....................",
".......xxxxxx.......",                      
".......xxxxxx.......",                     
".......xxxxxx.......",                          
"....................",
"....................",
"...................."    
};


char *p_pv[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
".......xxxxxx.......",                
".......xxxxxx.......",                      
".......xxxxxx.......",                     
"....................",
"....................",
"....................",
".......xxxxxx.......",                     
".......xxxxxx.......",                          
".......xxxxxx.......",                      
".......xxx..........",                     
".......x............"    
};


char *p_menos[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",                
"....................",
"xxxxxxxxxxxxxxxxxxxx",                      
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"....................",                     
"....................",                      
"....................",                          
"....................",                     
"....................",                      
"...................."    
};

char *p_[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"....................",                
"....................",
"....................",                     
"....................",                      
"....................",                          
"....................",                     
"....................",                      
"....................",
"xxxxxxxxxxxxxxxxxxxx",                      
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx"    
};

char *p_equal[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"....................",
"....................",
"xxxxxxxxxxxxxxxxxxxx",                      
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",                    
"....................",                      
"....................",                          
"xxxxxxxxxxxxxxxxxxxx",                      
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx", 
"....................",                     
"....................",                      
"...................."     
};

char *p_barra[] = {
"20 15 2",
". 0",
"x 2",
".............xxxxxxx",    
"............xxxxxxx.",     
"...........xxxxxxx..",      
"..........xxxxxxx...",       
".........xxxxxxx....",        
"........xxxxxxx.....",         
".......xxxxxxx......",               
"......xxxxxxx.......",            
".....xxxxxxx........",             
"....xxxxxxx.........",              
"...xxxxxxx..........",               
"..xxxxxxx...........",                
".xxxxxxx............",                 
"xxxxxxx.............",                  
"...................."   
};

char *p_par1[] = {
"20 15 2",
". 0",
"x 2",
"..........xxxxxx....",             
"........xxxxxxxxx...",            
".......xxxxxxxxxx...",             
"......xxxxxxxxxx....",              
"......xxxxxxxx......",                
"......xxxxxxx.......",                           
"......xxxxxxx.......",                     
"......xxxxxxx.......",                         
"......xxxxxxx.......",                      
"......xxxxxxx.......",                                     
"......xxxxxxxx......",                
"......xxxxxxxxxx....",              
".......xxxxxxxxxx...",          
".........xxxxxxxxx..",            
"...........xxxxxx..."   
};

char *p_par2[] = {
"20 15 2",
". 0",
"x 2",
"....xxxxxx..........",             
"...xxxxxxxxx........",            
"...xxxxxxxxxx.......",             
"....xxxxxxxxx.......",              
"......xxxxxxx.......",                
"......xxxxxxx.......",                           
"......xxxxxxx.......",                     
"......xxxxxxx.......",                         
"......xxxxxxx.......",                      
"......xxxxxxx.......",                                     
"......xxxxxxx.......",                
".....xxxxxxxx.......",              
"...xxxxxxxxxx.......",          
"...xxxxxxxxx........",            
"....xxxxxx.........."   
};

char *p_barra_c[] = {
"20 15 2",
". 0",
"x 2",

"xxxxxxx.............",
".xxxxxxx............",  
"..xxxxxxx...........",
"...xxxxxxx..........",
"....xxxxxxx.........",
".....xxxxxxx........",
"......xxxxxxx.......",
".......xxxxxxx......",
"........xxxxxxx.....",
".........xxxxxxx....",
"..........xxxxxxx...",
"...........xxxxxxx..",
"............xxxxxxx.",
".............xxxxxxx",
"...................." 
};

char *p_apos[] = {
"20 15 2",
". 0",
"x 2",
".......xxxxxx.......",                     
".......xxxxxx.......",                          
".......xxxxxx.......",                      
".......xxx..........",                     
".......x............", 
"....................",
"....................",
"....................",
"....................",
"....................",                
"....................",
"....................",
"....................",
"....................",
"...................."  
};

char *p_hash[] = {
"20 15 2",
". 0",
"x 2",
"....................",                          
"....xxxx....xxxx....",     
"....xxxx....xxxx....",    
"....xxxx....xxxx....",    
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"....xxxx....xxxx....",    
"....xxxx....xxxx....",    
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxx",
"....xxxx....xxxx....",     
"....xxxx....xxxx....",
"....xxxx....xxxx...."    
};

char *p_mais[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",                              
".......xxxxxxx......",           
".......xxxxxxx......",    
".......xxxxxxx......",     
"..xxxxxxxxxxxxxxxxx.",      
"..xxxxxxxxxxxxxxxxx.",      
"..xxxxxxxxxxxxxxxxx.",    
"..xxxxxxxxxxxxxxxxx.",    
".......xxxxxxx......",           
".......xxxxxxx......",    
".......xxxxxxx......",
"....................",
"....................",
"...................."   
};

char *p_par_ret1[] = {
"20 15 2",
". 0",
"x 2",
"......xxxxxxxxxx....",                 
"......xxxxxxxxxx....",                 
"......xxxxxxxxxx....",                 
"......xxxxxxxxxx....",                 
"......xxxxxx........",                    
"......xxxxxx........",                      
"......xxxxxx........",
"......xxxxxx........",
"......xxxxxx........",
"......xxxxxx........",
"......xxxxxx........",      
"......xxxxxxxxxx....",                 
"......xxxxxxxxxx....",                 
"......xxxxxxxxxx....",                 
"......xxxxxxxxxx...."    
};

char *p_par_ret2[] = {
"20 15 2",
". 0",
"x 2",
"...xxxxxxxxxx.......",                 
"...xxxxxxxxxx.......",                 
"...xxxxxxxxxx.......",                 
"...xxxxxxxxxx.......",                 
".......xxxxxx.......",                    
".......xxxxxx.......",                      
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",      
"...xxxxxxxxxx.......",                 
"...xxxxxxxxxx.......",                 
"...xxxxxxxxxx.......",                 
"...xxxxxxxxxx......."   
};

char *p_ecom[] = {
"20 15 2",
". 0",
"x 2",
".....xxxxxxxxxx.....",          
"....xxxxxxxxxxxx....",         
"...xxxxxxxxxxxxxx...",        
"..xxxxxx...xxxxxx...",        
"..xxxxxx...xxxxxx...",   
"...xxxxxxxxxxxxxx...",         
"....xxxxxxxxxxxx....",          
".....xxxxxxxxx......",    
"...xxxxxxxxxx...xxxx",      
"..xxxxxxxxxxx..xxxxx",      
".xxxxxxx....xxxxxxxx",      
"xxxxxxx......xxxxx..",        
".xxxxxxxxxxxxxxxxxxx",      
"..xxxxxxxxxxxxxxxxxx",      
"....xxxxxxxx...xxxxx"   
};

char *p_ou[] = {
"20 15 2",
". 0",
"x 2",
".......xxxxxx.......",                    
".......xxxxxx.......",                      
".......xxxxxx.......",
".......xxxxxx.......",                 
".......xxxxxx.......",                    
".......xxxxxx.......",                      
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",
".......xxxxxx.......",      
".......xxxxxx.......",                    
".......xxxxxx.......",                      
".......xxxxxx.......",
".......xxxxxx......."  
};


char *p_perc[] = {
"20 15 2",
". 0",
"x 2",
"..xxxxx......xxxxxx.",
".xxxxxxx....xxxxxx..",
"..xxxxx....xxxxxx...",
"..........xxxxxx....",
".........xxxxxx.....",
"........xxxxxx......",
".......xxxxxx.......",       
"......xxxxxx........",        
".....xxxxxx.........",         
"....xxxxxx..........",          
"...xxxxxx...........",           
"..xxxxxx.....xxxxx..",
".xxxxxx.....xxxxxxx.",
"xxxxxx.......xxxxx..",
"...................."  
};

char *p_chav1[] = {
"20 15 2",
". 0",
"x 2",
".....xxxxxxx........",
"...xxxxxxx..........",
"...xxxxxx...........",
"...xxxxxx...........",
"...xxxxx............",  
"..xxxxxx............",  
".xxxxxx.............",     
"xxxxxx..............",    
".xxxxxx.............",   
"..xxxxxx............",  
"...xxxxx............",  
"...xxxxx............",  
"...xxxxxx...........",
"...xxxxxxx..........",
".....xxxxxxx........"    
};

char *p_chav2[] = { //fazer a }
"20 15 2",
". 0",
"x 2",
".....xxxxxxx........",
"...xxxxxxx..........",
"...xxxxxx...........",
"...xxxxxx...........",
"...xxxxx............",  
"..xxxxxx............",  
".xxxxxx.............",     
"xxxxxx..............",    
".xxxxxx.............",   
"..xxxxxx............",  
"...xxxxx............",  
"...xxxxx............",  
"...xxxxxx...........",
"...xxxxxxx..........",
".....xxxxxxx........"    
};

char *p_ast[] = {
"20 15 2",
". 0",
"x 2",
"xxxxxx........xxxxxx",     
"xxxxxxx......xxxxxxx",     
"xxxxxxxxxxxxxxxxxxxx",     
"...xxxxxxxxxxxxxx...",        
"xxxxxxxxxxxxxxxxxxxx",     
"xxxxxxxxxxxxxxxxxxxx",     
"xxxxxxxxxxxxxxxxxxxx",     
"...xxxxxxxxxxxxxx...",        
"xxxxxxxxxxxxxxxxxxxx",     
"xxxxxxx......xxxxxxx",     
"xxxxxx........xxxxxx",     
"....................",
"....................",
"....................",
"...................."   
};

char *p_menor[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
"..........xxxxxxx...",
"........xxxxxxx.....",
"......xxxxxxx.......",
"....xxxxxxx.........",
"...xxxxxxx..........",     
".xxxxxxx............",      
"...xxxxxxx..........",     
"....xxxxxxx.........",
"......xxxxxxx.......",
"........xxxxxxx.....",
"..........xxxxxxx...",
"....................",
"...................."   
};

char *p_maior[] = {
"20 15 2",
". 0",
"x 2",
"....................",
"....................",
".....xxxxxxx........",
".......xxxxxxx......",
"........xxxxxxx.....",
"..........xxxxxxx...",
"...........xxxxxxx..",     
".............xxxxxxx",      
"...........xxxxxxx..",     
"..........xxxxxxx...",
"........xxxxxxx.....",
".......xxxxxxx......",
".....xxxxxxx........",
"....................",
"...................."   
};



char *read_xpm(char *map[], int *wd, int *ht)
{
  int width, height, colors;
  char sym[256];
  int  col;
  int i, j;
  char *pix, *pixtmp, *tmp, *line;
  char symbol;

  /* read width, height, colors */
  if (sscanf(map[0],"%d %d %d", &width, &height, &colors) != 3) {
    printf("read_xpm: incorrect width, height, colors\n");
    return NULL;
  }
  if (width > 1024 || height > 768 || colors > 256) {
    printf("read_xpm: incorrect width, height, colors\n");
    return NULL;
  }

  *wd = width;
  *ht = height;

  for (i=0; i<256; i++)
    sym[i] = 0;

  /* read symbols <-> colors */
  for (i=0; i<colors; i++) {
    if (sscanf(map[i+1], "%c %d", &symbol, &col) != 2) {
    	vg_exit();
      printf("read_xpm: incorrect symbol, color at line %d\n", i+1);
      exit(1);
      return NULL;
    }
    if (col > 256) {
    	vg_exit();
      printf("read_xpm: incorrect color at line %d\n", i+1);
      exit(1);
      return NULL;
    }
    sym[col] = symbol;
  }
  
  /* allocate pixmap memory */
  pix = pixtmp = malloc(width*height);

  /* parse each pixmap symbol line */
  for (i=0; i<height; i++) {
    line = map[colors+1+i];
    for (j=0; j<width; j++) {
      tmp = memchr(sym, line[j], 256);  /* find color of each symbol */
      if (tmp == NULL) {
      	vg_exit();
    	  printf("read_xpm: incorrect symbol at line %d, col %d\n", colors+i+1, j);
    	  exit(1);
    	  return NULL;
      }
      *pixtmp++ = tmp - sym; 
    }
  }

  return pix;
}



void loadXpms(){
	int w,h;
	mapXpms[0] = read_xpm(A,&w,&h);
	mapXpms[1] = read_xpm(B,&w,&h);
	mapXpms[2] = read_xpm(C,&w,&h);
	mapXpms[3] = read_xpm(D, &w, &h);
	mapXpms[4] = read_xpm(E, &w, &h);
	mapXpms[5] = read_xpm(F, &w, &h);
	mapXpms[6] = read_xpm(G, &w, &h);
	mapXpms[7] = read_xpm(H, &w, &h);
	mapXpms[8] = read_xpm(I, &w, &h);
	mapXpms[9] = read_xpm(J, &w, &h);
	mapXpms[10] = read_xpm(K, &w, &h);
	mapXpms[11] = read_xpm(L, &w, &h);
	mapXpms[12] = read_xpm(M, &w, &h);
	mapXpms[13] = read_xpm(N, &w, &h);
	mapXpms[14] = read_xpm(O, &w, &h);
	mapXpms[15] = read_xpm(P, &w, &h);
	mapXpms[16] = read_xpm(Q, &w, &h);
	mapXpms[17] = read_xpm(R, &w, &h);
	mapXpms[18] = read_xpm(S, &w, &h);
	mapXpms[19] = read_xpm(T, &w, &h);
	mapXpms[20] = read_xpm(U, &w, &h);
	mapXpms[21] = read_xpm(V, &w, &h);
	mapXpms[22] = read_xpm(W, &w, &h);
	mapXpms[23] = read_xpm(X, &w, &h);
	mapXpms[24] = read_xpm(Y, &w, &h);
	mapXpms[25] = read_xpm(Z, &w, &h);
	mapXpms[26] = read_xpm(a, &w, &h);
	mapXpms[27] = read_xpm(b, &w, &h);
	mapXpms[28] = read_xpm(c, &w, &h);
	mapXpms[29] = read_xpm(d, &w, &h);
	mapXpms[30] = read_xpm(e, &w, &h);
	mapXpms[31] = read_xpm(f, &w, &h);
	mapXpms[32] = read_xpm(g, &w, &h);
	mapXpms[33] = read_xpm(lh, &w, &h);
	mapXpms[34] = read_xpm(i, &w, &h);
	mapXpms[35] = read_xpm(j, &w, &h);
	mapXpms[36] = read_xpm(k, &w, &h);
	mapXpms[37] = read_xpm(l, &w, &h);
	mapXpms[38] = read_xpm(m, &w, &h);
	mapXpms[39] = read_xpm(n, &w, &h);
	mapXpms[40] = read_xpm(o, &w, &h);
	mapXpms[41] = read_xpm(p, &w, &h);
	mapXpms[42] = read_xpm(q, &w, &h);
	mapXpms[43] = read_xpm(r, &w, &h);
	mapXpms[44] = read_xpm(s, &w, &h);
	mapXpms[45] = read_xpm(t, &w, &h);
	mapXpms[46] = read_xpm(u, &w, &h);
	mapXpms[47] = read_xpm(v, &w, &h);
	mapXpms[48] = read_xpm(lw, &w, &h);
	mapXpms[49] = read_xpm(x, &w, &h);
	mapXpms[50] = read_xpm(y, &w, &h);
	mapXpms[51] = read_xpm(z, &w, &h);
	mapXpms[52] = read_xpm(n1, &w, &h);
	mapXpms[53] = read_xpm(n2, &w, &h);
	mapXpms[54] = read_xpm(n3, &w, &h);
	mapXpms[55] = read_xpm(n4, &w, &h);
	mapXpms[56] = read_xpm(n5, &w, &h);
	mapXpms[57] = read_xpm(n6, &w, &h);
	mapXpms[58] = read_xpm(n7, &w, &h);
	mapXpms[59] = read_xpm(n8, &w, &h);
	mapXpms[60] = read_xpm(n9, &w, &h);
	mapXpms[61] = read_xpm(n0, &w, &h);
	mapXpms[62] = read_xpm(esp, &w, &h);
}

