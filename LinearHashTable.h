#ifndef LINEARHASHTABLE_H
#define LINEARHASHTABLE_H
// This is the node for the value node in the hash table
class node
{
public:
	int value;

	node(int user_val)
	{
		value = user_val;
	}
};

// This is the class for the hash table where insert delete and find funtions will be performed
class HashTable
{
public:

	HashTable();
	int getIndex(int);
	int insert(int);
	int find(int);
	int remove(int);
	void print();
	~HashTable();

	// Test function
	int getspot()
	{
		return spot_left;
	}

private:
	node** hashtable;		// The array of pointers
	int Max_size;			// The size of the table
	int spot_left;			// number of spot left one the table
};

HashTable::HashTable()
{
	Max_size = 500;
	spot_left = Max_size;
	hashtable = new node*[Max_size];

	// fill up the table with null values
	for (int i = 0; i < Max_size; i++)
	{
		hashtable[i] = NULL;
	}
}
// --------------------------------------------------------------------------------------------
// This function takes a int value for the key that user is trying to insert. It take the mod 
// of that value with size to determine the location for that value. It taking the mod it returns
// the int type. 
// --------------------------------------------------------------------------------------------
int HashTable::getIndex(int value)
{
	return value % Max_size;

}
// --------------------------------------------------------------------------------------------
// This is the insert function. This accepts a int for the value to be inserted in the table.
// this has return type of int which is the count of spot it had to check to find empty spot
// to insert the value;
// --------------------------------------------------------------------------------------------
int HashTable::insert(int value)
{
	int count_collision = 1; // stores the spots check | count collsion to return it
	// if the table is full
	if (spot_left == 0)
	{
		cout << "THE TABLE IS FULL" << endl;
		return 0;
	}
	int index = getIndex(value);
	while (hashtable[index] != nullptr)
	{
		// count collsion here
		count_collision++;
		index = (index + 1) % Max_size;
	}
	
	node* temp = new node(value);
	hashtable[index] = temp;
	spot_left--;
	return count_collision;

}
// --------------------------------------------------------------------------------------------
// This is the remove function. This accepts a int for the value to be deleted.
// This function return in which is for the number of spot searched to find that
// value in the table and delete it.
// --------------------------------------------------------------------------------------------
int HashTable::remove(int key)
{
	int count_remove = 0;
	int index = getIndex(key);
	// start search the table from the index value rather than beginning of the table
	while (hashtable[index] != NULL)
	{
		count_remove++;									// first check when it check whether the location is empty or not 
		// check if we found the key or not
		if (hashtable[index]->value == key)
		{	
			count_remove++;								// Scond check when it checks whether the value to remove matches or not
			 hashtable[index] = nullptr;
		}
		index++;                 // if the key doesn't match move up the table until it find 
	}
	
	return count_remove;			
}
// --------------------------------------------------------------------------------------------
// This is the find function. This accepts a int for value to find.
// It return int which is for the count on number of spot it checked
// while searching for the value in the table.
// --------------------------------------------------------------------------------------------
int HashTable::find(int key)
{
	int count_remove = 0;
	int index = getIndex(key);
	// start search the table from the index value rather than beginning of the table
	while (hashtable[index] != NULL)
	{
		count_remove++;									// first check when it check whether the location is empty or not 
		// check if we found the key or not
		if (hashtable[index]->value == key)
		{
			count_remove++;								// Scond check when it checks whether the value to remove matches or not
		}
		index++;                 // if the key doesn't match move up the table until it find 
	}

	return count_remove;
}

// This prints the hash table
void HashTable::print()
{
	for (int i = 0; i < Max_size; i++)
	{
		if (hashtable[i] == nullptr )
		{
			cout << i << ". Empty" << endl;
		}
		else
		{
		cout << i << ". "<< hashtable[i]->value << endl;
		}
		
	}
}
HashTable::~HashTable()
{
	for (int i = 0; i < Max_size; i++)
	{
		delete hashtable[i];
	}
}
#endif // LINEARHASHTABLE_H
