//Создание структуры с студентами и их оценками
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Создание структуры
struct Student
{
    char Name[20];
    int Group;
    int Marks[3];
};


void Bubble_sort(struct Student *massive, int length_array)
{
  int c;
  FILE *txt;
  for (int i=0; i < (length_array) -1; i++) {
    for (int j=0; j <(length_array)-i-1; j++) {
      if (massive[j].Group > massive[j+1].Group) {
        c = massive[j].Group;
        massive[j].Group = massive[j+1].Group;
        massive[j+1].Group = c;
      }
    }
  }
  txt = fopen("Students.txt", "w");
    fprintf (txt,"№     Name        Group       Marks\n");
    int d = 0;
    for (int i = 0; i < length_array; i++)
    {
        int test = 1;
        for (int b = 0; b < 3;b++)
        {
        if (massive[i].Marks[b] == 3 || massive[i].Marks[b] ==2 || massive[i].Marks[b] ==1 )
        {
            test = 0;
            continue;
        }
        }
        if (test != 0)
        {
        
        fprintf(txt,"%-5d%-15s%-10d",i,massive[i].Name,massive[i].Group);
        for (int b = 0; b < 3; b++)
        {
            fprintf (txt,"%d ",massive[i].Marks[b]);
        }
        fprintf (txt,"\n");
        d++;
        test++;
        }
    }
    fclose (txt);
}

int CounterOfObjects ()
{
  FILE *file;  
  char buffer[20];
  int count = 0;
  file = fopen("students.json", "r");
  while (fscanf(file, "%s", buffer) != EOF)
  {
      for (int i = 0; i <strlen(buffer); i++)
      {
          if (buffer[i] == '}')
          count++;
      }
  }
  fclose(file);
  return count;
}

void parser ()
{
    FILE *file;
    char buffer[20];
    struct Student *list = NULL;
    int counter = CounterOfObjects();
    list = (struct Student*)malloc( sizeof(struct Student) * counter);
    file = fopen("students.json", "r");
    int CountFromStart = 0;
    while (fscanf(file, "%s", buffer) != EOF)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ':' && buffer[i+1] == '"')
            {
                char temp[sizeof(buffer)];
                i += 2;
                for (int c = 0; c < 20; c++)
                {
                    if (buffer[i] != '"')
                   {
                       temp[c] = buffer[i];
                       i++;
                   }
                   else break;
                }
                strcpy (list[CountFromStart].Name,temp);
                memset (temp,0,sizeof(temp));
                
            }
            // scan name
            if (buffer[i] == ':' && buffer[i+1] != '"' && buffer[i+1] != '[' )
            {
                int a = 0;
                i++;
                char temp[sizeof(buffer)];
                while (buffer[i] != ',')
                {
                    temp[a] = buffer[i];
                    a++;
                    i++;
                }
                list[CountFromStart].Group = atoi(temp);
                
            }
            
            if (buffer[i] == ':' && buffer[i+1] == '[')
            {
                i += 2;
                int a = 0;
                char temp;
                while (buffer[i] != ']')
                {
                    if (buffer[i] != ',' && buffer[i] != ']')
                    {
                    temp = buffer[i];
                    list[CountFromStart].Marks[a] = atoi(&temp);
                    i++;
                    a++;
                    }
                    else
                    i++;
                }
                CountFromStart++;
            }
            

        }

    }
    fclose(file);
    Bubble_sort(list,counter);
 
}
int main()
{   
    parser();
    return 0;
}