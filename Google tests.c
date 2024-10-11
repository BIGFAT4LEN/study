#include "gtest/gtest.h"
#include <stdio.h>

char arr[] = "124353adbrew";
char *p = arr;

int MaxIndex (char *arr)
{
	int Index = 0;
	int max = 0;
	for (int i = 0; i <strlen(arr); i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			Index = i;
		}
	}
return(Index);
}




//Гугл тесты
//2
TEST(bytes_of_int,sizeof_int)
{
	ASSERT_EQ(4,sizeof(int));          								  
}

//3
TEST(bytes,pointer_of_char)
{
	EXPECT_EQ(8,sizeof(char*));          							 
}

//4
TEST(bytes_void,pointer_of_void)
{
	EXPECT_EQ(8,sizeof(void*));            							 
}

//1
TEST(arr,MaxIndex)
{
	int result = 0;
	result = MaxIndex(arr);					 						 					
	EXPECT_EQ(11,result);
}

//5
TEST(bytes_of_char,pointer_of_pointer)
{
	EXPECT_EQ(8,sizeof(char**));								    
}

//6
TEST(bytes_of_arr,byte)
{
	EXPECT_EQ(13,sizeof(arr));										
}

//7
TEST(first,byte_of_first)
{
	EXPECT_EQ(1,sizeof(arr[0]));									
}

//8
TEST(length,bytes_char)
{
	EXPECT_EQ(strlen(arr)+1,sizeof(arr)); 							
}

//9
TEST(arr1,arr2)
{
	ASSERT_NE(sizeof(arr),sizeof(p));								
}

TEST(array1,array2)
{
	ASSERT_EQ(arr,p);											
}

//10
TEST(array3,array4)
{
	ASSERT_EQ(arr,&arr[0]);														
}

TEST(array5,array6)
{
	ASSERT_EQ(p,&arr[0]);											
}

//11
TEST(array7,array8)
{
	ASSERT_EQ(&arr[1],p + 1);																	
}

TEST(array9,array10)
{
	ASSERT_EQ(&p[1],p + 1);											
}

TEST(array11,array12)
{
	ASSERT_EQ(&arr[1],&p[1]);											
}

//12
TEST(array13,array14)
{
	ASSERT_EQ(arr[1],*(p+1));																				
}

TEST(array15,array16)
{
	ASSERT_EQ(arr[1],p[1]);											
}

TEST(array17,array18)
{
	ASSERT_EQ(arr[1],1[p]);											
}

TEST(array19,array20)
{
	ASSERT_EQ(*(p+1),p[1]);											
}

TEST(array21,array22)
{
	ASSERT_EQ(*(p+1),1[p]);											
}

TEST(array23,array24)
{
	ASSERT_EQ(1[p],p[1]);											
}



int main() 
{
 
testing::InitGoogleTest();

return RUN_ALL_TESTS();
}

