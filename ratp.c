#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#define M_PI 3.14159265358979323846264338327950288   /* pi */


double deg2rad(double x){
  return M_PI*x/180;
}
 
double get_distance_m(double lat1, double lng1, double lat2, double lng2) {
  double earth_radius = 6371000;   // Terre = sphère de 6371km de rayon
  double rlo1 = deg2rad(lng1);    // CONVERSION
  double rla1 = deg2rad(lat1);
  double rlo2 = deg2rad(lng2);
  double rla2 = deg2rad(lat2);
  double dlo = (rlo2 - rlo1) / 2;
  double dla = (rla2 - rla1) / 2;
  double a = (sin(dla) * sin(dla)) + cos(rla1) * cos(rla2) * (sin(dlo) * sin(dlo));
  double d = 2 * atan2(sqrt(a), sqrt(1 - a));
  
  return (earth_radius * d);
}

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


void main(){
	srand ( time(NULL) );
	int aleatoire=rand();
	
	//double n = get_distance_m(48.8812991447,2.27191517268,48.8470164776, 2.410816879);
	//printf("Distance entre 2 stations en m = %lf m \n", n);
	//printf("Distance entre 2 stations en km = %.3lf km", n/1000);

	FILE* file = fopen("gares-du-reseau-ferre-dile-de-france.csv", "r");

	char ville1[25];
	char ville2[25];
    char line[1024];
    
    while (fgets(line, 1024, file)){
        char* tmp = strdup(line);
        char* tmp2 = strdup(line);
        char* tmp3 = strdup(line);
        char* tmp4 = strdup(line);
        char* tmp5 = strdup(line);
        char* tmp6 = strdup(line);
        char* tmp7 = strdup(line);
        char* tmp8 = strdup(line);
        char* tmp9 = strdup(line);
        char* tmp10 = strdup(line);
        
   		int v1= atoi(ville1);
		int v2= atoi(ville2);

        
        
      // printf("Latitude des stations %s\n", getfield(tmp, 1));
      //	printf("Distance entre 2 stations (%s,%s)  \n",getfield(tmp, 3) ,getfield(tmp2, 3));

       // printf("Longitude des stations %s\n", getfield(tmp2, 2));
       
       for (v1=1;v1<10;v1++)
	   {
    //	printf("Ville 1 = %s\n",getfield(tmp9, 4));
			for (v2=1;v2<10;v2++)
			{
       			v1= getfield(tmp9, 4);
       			//	printf("Ville 2 = %s\n",getfield(tmp10, 4));
       			v2=getfield(tmp10,10);
       			printf("------------------------------------------------");
       			printf("\nVille 1 = %s , Ville 2 = %s \n",ville1,ville2);
       	
				if (strcmp(ville1,ville2) != 0)
				{
       				double n = get_distance_m(atof(getfield(tmp, 1)),atof(getfield(tmp2, 2)),atof(getfield(tmp3, 11)),atof(getfield(tmp4, 12)));
       				//	printf("n= %lf",n);
					//printf("Distance entre 2 stations (%s,%s) en m = %lf m \n",getfield(tmp5, 4) ,getfield(tmp6, 10),n);
					printf("\n");
					//	printf("Distance entre 2 stations (%s,%s) en km = %.3lf km\n",getfield(tmp7, 4) ,getfield(tmp8, 10), n/1000);
		       		printf("\n");
		       		printf("Distance entre 2 stations (%s,%s) en min avec une vitesse de 60 km/h = %.0lf min\n",getfield(tmp5, 4) ,getfield(tmp6, 10), (60*(n/1000)/60));

       			}
       		}
       }
	/*	double n = get_distance_m(atof(getfield(tmp, 1)),atof(getfield(tmp2, 2)),atof(getfield(tmp3, 1)),atof(getfield(tmp4, 2)));
		printf("Distance entre 2 stations (%s,%s) en m = %lf m \n",rand() %1+getfield(tmp5, 4) ,rand() %1+getfield(tmp6, 4),n);
		printf("\n");
		printf("Distance entre 2 stations (%s,%s) en km = %.3lf km\n",rand() %1+getfield(tmp7, 4) ,rand() %1+getfield(tmp8, 4), n/1000);
       printf("\n");
       */
        free(tmp);
        free(tmp2);
        free(tmp3);
        free(tmp4);
        free(tmp5);
        free(tmp6);
        free(tmp7);
        free(tmp8);
        free(tmp9);
        free(tmp10);

    }
}
//for e in l
//for e2 in l
//if 


