#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ifttt.h"


int main(int argc, char **argv) {
    
	FILE *fp;
        int n;
	double temp;
	double high;
	double low;
	double now;
       
        char buffer[6];
	char highest[10];
	char lowest[10];
	char present[10];

	time_t seconds;
	seconds = time(NULL);

        while(1){ 
	
	
	/*while(time(NULL) < seconds + 1){	
	
	}*/
	
	fp = fopen("/sys/bus/w1/devices/28-021313cd9faa/w1_slave", "r");
        if (fp == (FILE *)NULL ) {
                perror("opening of file failed");
                exit(1);
        
	}
	
        fseek(fp, 69, SEEK_SET);

	n = fread(buffer, 5, 1, fp);
        if (n == 0) {
                perror("read failed!");
                exit(1);
        }

	sscanf(buffer, "%lf", &temp);
	temp = temp/1000;

	if(now == 0.0){
		now = temp;
		high = temp;
		low = temp;
		sprintf(present,"%lf", now);	
		sprintf(highest,"%lf", high);
		sprintf(lowest,"%lf", low);	
		ifttt("https://maker.ifttt.com/trigger/thermo_changed/with/key/d5ioREkc3MC0JY8Zye0mu1", present, highest, lowest);	
	
	
	}

	if(temp - now  > 1){
		if(temp > high){
			high = temp;
			sprintf(highest,"%lf", high);
		ifttt("https://maker.ifttt.com/trigger/thermo_changed/with/key/d5ioREkc3MC0JY8Zye0mu1", present, highest, lowest);	
		
		}
		else{
			now=temp;
			sprintf(present,"%lf", now);	
			ifttt("https://maker.ifttt.com/trigger/thermo_changed/with/key/d5ioREkc3MC0JY8Zye0mu1", present, highest, lowest);	
			
		}
	}

	if(temp - now < - 1){
		if(temp < low){
			low = temp;
			sprintf(lowest,"%lf", low);
			ifttt("https://maker.ifttt.com/trigger/thermo_changed/with/key/d5ioREkc3MC0JY8Zye0mu1", present, highest, lowest);	
		
		}
		else{
			now=temp;
			sprintf(present,"%lf", now);	
			ifttt("https://maker.ifttt.com/trigger/thermo_changed/with/key/d5ioREkc3MC0JY8Zye0mu1", present, highest, lowest);	
			
		}

		
		
		
	}


	

       
	printf("now %lf\t high %lf\t low %lf\n", now, high, low);

        fclose(fp);
	
	}
		
        return 0;  
}

         

