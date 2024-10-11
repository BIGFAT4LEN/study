//Реверс слов, без затрагивания знаков препинания

#include <stdio.h>
#include <string.h>
#include <malloc.h>
void reverse(char *message,char *string,int start, int end) //функция для реверса слов
{
    for (int i=0 ;i < strlen(message) ; i++) //создаем цикл для того, чтобы пройтись по всему предложению, записанному в массив. Реверсим каждое слово по отдельности
        {
        if (message[i]==' ' || message[i]==',' || message[i]=='\0'|| message[i]=='!'|| message[i]==';' ) //пропускаем знаки препинания и пробелы, чтобы они остались на изначальных позициях
            {
                end = i - 1; 
                char temp;
                for(int j =0; j<(end-start)/2; j++) //меняем местами буквы в слове
                {
                    temp = string[start +j];
                    string[start+j] = string[end-j];
                    string[end-j] = temp;
                }
                start = i + 1; //обновляем значение старт, чтобы начать со следующего слова в предложении
            }
        }
}
int main()
{
    char message[] = "Hello world!"; // записываем в массив, предложение, которое хотим перевернуть
    //printf("Enter your text\n"); можно сделать ввод предложения пользователем
    //fgets(message, 256, stdin);
    char *mass=(char*) malloc((strlen(message)+1)*sizeof(char));
    strcpy(mass,message);
    int start=0, end = 0;
    reverse(message , mass , start , end); //запуск функции реверса
    printf("Revers stroke: %s\n", mass); //вывод перевернутого предложения
    free(mass); //освобождаем массива
    return 0;
}