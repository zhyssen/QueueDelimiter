// This program checks a string to see if it is properly delimited with corresponding
// opening and closing parentheses or brackets. The string of characters is read into 
// a queue, then the queue is checked for proper delimination with parentheses.

#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Function to check if properly delimited
void checkDelimiter(string value)
{
	queue <char> charQueue;

	for (int x = 0; x < value.length(); x++)
	{
		// Store opening parentheses into stack
		if (value[x] == '(' || value[x] == '[' || value[x] == '{')
		{
			charQueue.push(value[x]);
		}
		else if (value[x] == ')' || value[x] == ']' || value[x] == '}')
		{
			// Look for closing parentheses and check for match with opening parentheses
			if (charQueue.empty())
			{
				cout << "The string is not properly delimited." << endl;
				return;
			}

			if (value[x] == ')' && charQueue.back() == '(')
			{
				charQueue.pop();
			}
			else if (value[x] == ']' && charQueue.back() == '[')
			{
				charQueue.pop();
			}
			else if (value[x] == '}' && charQueue.back() == '{')
			{
				charQueue.pop();
			}
			else
			{
				cout << "The string is not properly delimited." << endl;
				return;
			}
		}
	}

	// Output results
	if (charQueue.empty())
	{
		cout << "The string is properly delimited." << endl;
	}
	else
	{
		cout << "The string is not properly delimited." << endl;
	}
}

int main()
{
	// Variable
	string value;

	// Get user input
	cout << "Enter a string of characters or words with or without parentheses: \n";
	cout << "(Parenetheses can include (), {}, or [].)\n";
	getline(cin, value);

	// Call the checkDelimiter function
	checkDelimiter(value);

	return 0;
}