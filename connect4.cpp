#include <iostream>
using namespace std;

bool wincheck (int A[10][10], int row, int column, int player, int a, int b)
{
/*
  0 is right, 1 is down,  2 is left, 3 is top-right, 4 is botton-right, 5 is bottom left, 6 is top left
*/
int i, j, direction[7] = {1,1,1,1,1,1,1}; 
bool keep_going = true;
int temp_a = a, temp_b = b;

while (keep_going == true)
{

	if (temp_b<column && A[temp_a][temp_b+1] == player)
	{
		direction[0] += 1;
		temp_b += 1;
	}
	else
		keep_going = false;
}


keep_going = true;
temp_a = a;
temp_b = b;

while (keep_going == true)
{
	if (temp_a<row && A[temp_a+1][temp_b] == player)
	{
		direction[1] += 1;
		temp_a += 1;
	}
	else
		keep_going = false;
}

keep_going = true;
temp_a = a;
temp_b = b;

while (keep_going == true)
{
	if (temp_b>0 && A[temp_a][temp_b-1] == player)
	{
		direction[2] += 1;
		temp_b -= 1;
	}
	else
		keep_going = false;
}

keep_going = true;
temp_a = a;
temp_b = b;

while (keep_going == true)
{
	if (temp_a>0 && temp_b<column && A[temp_a-1][temp_b+1] == player)
	{
		direction[3] += 1;
		temp_a -= 1;
		temp_b += 1;
	}
	else
		keep_going = false;
}

cout<<endl;

keep_going = true;
temp_a = a;
temp_b = b;

while (keep_going == true)
{
	if (temp_a<row && temp_b<column && A[temp_a+1][temp_b+1] == player)
	{
		direction[4] += 1;
		temp_a += 1;
		temp_b += 1;
	}
	else
		keep_going = false;
}

keep_going = true;
temp_a = a;
temp_b = b;

while (keep_going == true)
{
	if (temp_a<row && temp_b>0 && A[temp_a+1][temp_b-1] == player)
	{
		direction[5] += 1;
		temp_a += 1;
		temp_b -= 1;
	}
	else
		keep_going = false;
}

keep_going = true;
temp_a = a;
temp_b = b;

while (keep_going == true)
{
	if (temp_a>0 && temp_b>0 && A[temp_a-1][temp_b-1] == player)
	{
		direction[6] += 1;
		temp_a -= 1;
		temp_b -= 1;
	}
	else
		keep_going = false;
}


if ( direction[0] + direction [2]  == 5 )
	return true;
else if (direction[1] == 4)
	return true;
else if ( direction[3] + direction[5]  == 5)
	return true;
else if ( direction[4] + direction[6] == 5)
	return true;
else
	return false;


}

int main()
{
int row, column, A[10][10], i, j, player = 1;
bool win = false;

cout<<"Enter number of rows and columns (max 10) : ";
cin>>row>>column;

//setting all elements to 0 at the beginning
for(i = 0; i<row; i++)
for(j = 0; j<column; j++)
A[i][j] = 0;

cout<<"Player 1 starts! Format ('x y') \n";

while (win == false)
{
for(i = 0; i<row; i++)
{
	for(j = 0; j<column; j++)
		{
		cout<<A[i][j]<<" ";
		}
	cout<<endl;
}
cout<<endl;
int a, b;
cout<<"Enter point : ";
cin>>a>>b;
while( A[a-1][b-1]==1 || A[a-1][b-1]==2 || a>row || b>column || ( a!= row && A[a][b-1] == 0))
	{
	cout<<"Occupied or invalid position : ";
	cin>>a>>b;
	cout<<endl;
	}
int temp = player;
if(player == 1)
	{
	A[a-1][b-1] = 1;
	player = 2;
	}
else if (player == 2)
	{
	A[a-1][b-1] = 2;
	player = 1;
	}
cout<<endl;

win = wincheck(A, row-1, column-1, temp, a-1, b-1);
if(win == true)
	{
	cout<<endl;
	for(i = 0; i<row; i++)
	{
		for(j = 0; j<column; j++)
		{
		cout<<A[i][j]<<" ";
		}
	cout<<endl;
	}
		cout<<"-----------------------------------\n";
		cout<<"Player "<<temp<<" has won the game! \n";
		cout<<"-----------------------------------\n";
	}
}
return 1;
}
