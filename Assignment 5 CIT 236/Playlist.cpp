#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

void Playlist::Resize(int newCapacity)
{
	capacity = newCapacity;
	//making a new array
	string* temp = new string[capacity];
	//copying the elements from the old array and assigning them to the new array
	for (int i = 0; i < size; ++i)
		temp[i] = songs[i];
	//deleting the old array
	delete[] songs;
	// using the old array
	songs = temp;
}
/*
Adding these Functions to "Playlist.cpp" because 
they're alittle longer than regular getting and setter
Im not sure if you can put operator overloads inside the cpp
because its not inside the class.
*/

void Playlist::Display()
{

	cout << size << " songs in playlist: " << "\"" << nameOfPlaylist << "\"" << endl;


	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << ": " << songs[i];
		cout << endl;
	}
}

void Playlist::AddSong(string songName) 
{
	if (size == capacity)
		Resize(capacity * 2);
	songs[size++] = songName;
}