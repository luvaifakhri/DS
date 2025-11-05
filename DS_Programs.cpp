1. Write a Program to Implement Bubble Sort 
#include<iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool isSwap = false;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				isSwap = true;
			}
		}
		if(!isSwap)
		{
			return;
		}
	}
}
void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n=5;
	int arr[] = {100,92,84,78,60};
	bubblesort(arr,n);
	printarray(arr,n);
	return 0;
}

====================================================================

2. Write a Program to Implement Quick Sort 
#include <iostream>
using namespace std;
// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;         // Index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot at the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// QuickSort function (recursive)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Find pivot

        // Recursively sort left and right parts
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Main function
int main() {
    int arr[] = { 24, 9, 29, 14, 19};
    int n = 5;
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}

====================================================================

3. Write a Program to Implement Selection Sort 
#include<iostream>
using namespace std;
void selectionsort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int smallest = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[smallest])
			{
				smallest = j;
			}
		}
		swap(arr[i],arr[smallest]);
	}
}
void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n=5;
	int arr[] = {100,92,184,78,60};
	selectionsort(arr,n);
	printarray(arr,n);
	return 0;
}

====================================================================

4. Write a Program to Implement Insertion Sort 
#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int current = arr[i];
		int j=i-1;
		while(arr[j]>current && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=current;
	}
}
void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n=5;
	int arr[] = {100,92,84,78,60};
	insertionsort(arr,n);
	printarray(arr,n);
	return 0;
}

====================================================================

5. Write a Program to Implement Linear Search 
#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x) return i;
    return -1;
}
int main() {
    int arr[] = {100, 20, 30, 40, 50,75};
    int n = sizeof(arr) / sizeof(arr[0]), x = 30;
    int result = linearSearch(arr, n, x);
    if(result == -1)
    	cout<<"Not Found ";
    else
    	cout<<"Found at Index "<<result;
	return 0;
}

====================================================================

6. Write a Program to Implement Binary Search 
#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]), x = 30;
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1) cout<<"Not found"; 
	else cout<<"Found at index " <<result;
    return 0;
}

====================================================================

7. Write a Program to Implement Stack Operations
#include<iostream>
using namespace std;
class stack
{
	int top;
	int size=5;
	int arr[5];
	public:
	stack()
	{
		top = -1;
	}
	void push(int value)
	{
		if(top == size-1)
		{
			cout<<"Stack is full";
		}
		else
		{
			top++;
			arr[top] = value;
			cout<<"Value Pushed";
		}
	}
	void pop()
	{
		if(top == -1)
		{
			cout<<"stack Underflow";
		}
		else
		{
			cout<<arr[top];
			top--;
			cout<<"Element Popped";
		}
	}
	void display()
	{
		if(top == -1)
		{
			cout<<"stack Underflow";
		}
		else
		{
			for(int i=top;i>=0;i--)
			{
				cout<<endl<<arr[i];
			}
		}
	}
};
int main()
{
	stack s;
	int choice,value;
	do
	{
	cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push\n2. Pop\n";
		cout<<"3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Exiting Program..." << endl;
            break;
        default:
            cout << "Invalid Choice! Try again.\n";
        }
    }while(choice != 4);
    return 0;
}

====================================================================

8. Write a Program to Implement Queue Operations 
#include <iostream>
using namespace std;
#define SIZE 5
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1){
            front = 0;
		}
        rear++;
        arr[rear] = value;
        cout << value << " inserted into the queue." << endl;
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot delete." << endl;
            return;
        }
        cout << arr[front] << " deleted from the queue." << endl;
        front++;
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }while (choice != 4);
    return 0;
}

====================================================================

9. Write a Program to Implement Recursion 
#include<iostream>
using namespace std;
void printtable(int num)
{
	static int i=1;
	if(i>10)
	{
		return;
	}
	cout<<endl<<num<<" x "<<i<<" = "<<num*i;
	i++;
	printtable(num);
}
int main()
{
	int num;
	cout<<"Multiplication Table to Print of Number : ";
	cin>>num;
	printtable(num);
	return 0;
}

====================================================================

10. Write a Program to Implement given Infix Expression into Postfix 
- Using Stack 
#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
// Function to check if the character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        // If operand, add to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')', pop till '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Pop '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                if (ch == '^' && st.top() == '^') break; // Right-associative '^'
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

====================================================================

10. Write a Program to Implement given Infix Expression into Postfix
- Using Recursion
#include <iostream>
#include <string>
using namespace std;
// Function to get precedence of operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else if (op == '^') return 3;
    return -1;
}
// Function to check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
// Recursive function to convert infix to postfix
string toPostfix(string expr) {
    int n = expr.length();
    // Remove surrounding brackets if present
    if (expr[0] == '(' && expr[n - 1] == ')') {
        int count = 0, valid = 1;
        for (int i = 0; i < n; i++) {
            if (expr[i] == '(') count++;
            else if (expr[i] == ')') count--;
            if (count == 0 && i != n - 1) valid = 0;
        }
        if (valid) return toPostfix(expr.substr(1, n - 2));
    }
    int pos = -1;
    int minPrec = 100;
    int brackets = 0;
    // Find the main operator (lowest precedence, outside brackets)
    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') brackets++;
        else if (expr[i] == ')') brackets--;
        else if (isOperator(expr[i]) && brackets == 0) {
            int prec = precedence(expr[i]);
            if (prec <= minPrec) {
                minPrec = prec;
                pos = i;
            }
        }
    }
    // If no operator, it's a single operand
    if (pos == -1) return expr;
    // Recursive conversion
    string left = toPostfix(expr.substr(0, pos));
    string right = toPostfix(expr.substr(pos + 1));
    return left + right + expr[pos];
}
// Main function
int main() {
    string infix = "a+(b*c-(d/e^f)*g)*h";
    cout << "Infix Expression: " << infix << endl;
    string postfix = toPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}

====================================================================