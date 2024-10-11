//Нахождение элемента в массиве с использованием пузырьковой сортировки
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//создание произвольного массива привязанного ко времени, с помощь. библиотеки time.h
void * malloc(size_t size);

char Clear(){
while ((getchar()) != '\n') {}
}

//Делаем пузырьковую сортировку, чтобы быстрее просканировать массив на наличие нужного нам числа
int Bubble_sort(int *massive, int length_array){
int c;
for (int i=0; i < length_array -1; i++) {
for (int j=0; j < length_array-i-1; j++) {
if (massive[j] > massive[j+1]) {
c = massive[j];
massive[j] = massive[j+1];
massive[j+1] = c;
}
}
}
for(int n = 0; n < length_array; n++){
printf("%d ", massive[n]);
}
printf("\n");
}

//функция поиска заданного числа 
int Binary_search(int *massive, int length_array, int find_num){
int left = 0;
int right = length_array;
int search = -1; 
while (left <= right){
int mid = (left + right) / 2; //делим массив, для быстроты нахлждения
if (find_num == massive[mid]) { //если центральное число и есть то, которое мы ищем, то функция записывает ее в ответ и продолжает сканирование массива
search = mid;
break;
}
if (find_num < massive[mid]) //поиск слева и справа
right = mid - 1; 
else
left = mid + 1; 
}
if (search == -1) //если такого числа нет в массиве, то выводится не найдено
printf("Dont find!\n");
else
printf(" left: massive[%d], right massive[%d]", left, right); //количество найденных элементов слева и справа
}

int main() {
char a;
int length_array, find_num;
int *massive = NULL;

do {

printf("length array: "); //задается длинна массива
scanf("%d", &length_array);
Clear();
printf("Find numer: "); //число которое ищем
scanf("%d", &find_num);
Clear();


massive = (int*) malloc(length_array * sizeof(int));

srand(time(NULL));

for(int i = 0; i < length_array; i++){
massive[i] = rand() % (2 * length_array);
}
for(int j = 0; j < length_array; j++){
printf("%d ", massive[j]);
}
printf("\n");
Bubble_sort(massive, length_array);

Binary_search(massive, length_array, find_num);

free(massive);
printf("Continue: (yes/no)"); //продолжать ли работу программы, или нет
scanf("%c", &a);
} while(a != 'n');

return 0;
} 