#pragma once

#include <string>
#include <iostream>					
									
using namespace std;				
									
class Playlist						
{									
private:							
	string nameOfPlaylist;					  
	//int numOfSongs = 1;						  
	string* songs = nullptr;				  
	int size = 0;							  
	int capacity = 2;						  
	

public:
	 
	Playlist(string name = "Untitled Playlist") //ctor
	{
		nameOfPlaylist = name;
		songs = new string[capacity];
	}
	
	~Playlist() // destructor
	{
		delete[] songs;
	}

	Playlist(Playlist& otherPlaylist) // copy ctor
	{
		*this = otherPlaylist;
	}

	Playlist& operator=(Playlist& otherPlaylist) // assignment operator overloading
	{
		if (this == &otherPlaylist) // skipping just in case of self assignment
			return *this;
		
		if (songs != nullptr) // deep copy, to stop from shallow copying
			delete[] songs;
		
		// copying 'otherPlaylist' size and capacity into the new object
		size = otherPlaylist.size;
		capacity = otherPlaylist.capacity; 
		nameOfPlaylist = otherPlaylist.nameOfPlaylist;

		
		songs = new string[capacity];
		for (int i = 0; i < size; ++i)
			songs[i] = otherPlaylist.songs[i];

		return *this;

	}


	string& operator[](int index) // Overloading the [] operator
	{
		return GetValue(index);
	}

	string& GetValue(int index) 
	{
		return songs[index];
	}
	
	void SetName(string name) 
	{
		nameOfPlaylist = name;
	}

	string GetName() const
	{
		return nameOfPlaylist;
	}
	
	void AddSong(string songName);
	
	void Resize(int newCapacity);

	void Display();	
	
};