#include <iostream>

#include "Playlist.h"
#include "MemLeakDetector.h"


using namespace std;

int main()
{
	//Assignment: Get this code working. The required output is listed below each section.
	//What you should do is comment out each chunk of this code and test them one at a time, starting with the simplest.
	//Check for memory leaks as you go as well:
		//Run in Debug Mode (F5, or click 'Local Windows Debugger' at the top, or go to Debug->Start Debugging)
		//Let the program finish and then check your Output Window (View->Output if you don't have it as a tab next to Error List)
		//It should NOT crash or report any memory leaks if your code is written correctly.

	cout << "Playlist 1: " << endl;
	Playlist playlist1("Favorites");
	playlist1.Display();
	/*Expected Output:
	0 Songs in Playlist "Favorites" */


		playlist1.AddSong("Ode to Joy");
		playlist1.AddSong("Vivaldi Springs");
		playlist1.AddSong("Beethoven's Symphony No. 5");
		playlist1.Display();
		/*Expected Output:
		3 Songs in Playlist "Favorites":
			1. Ode to Joy
			2. Vivaldi Springs
			3. Beethoven's Symphony No. 5 */
	

		cout << endl << endl << "Playlist 2: " << endl;
		Playlist playlist2(playlist1);
		playlist2.SetName("New Year's Music");
		playlist2.AddSong("Auld Lang Syne");
		playlist2[0] = "I Like To Move It";//HINT: [] is an operator that in this case would return string& (reference to a string)
		playlist2.Display();
		/*Expected Output:
		4 Songs in Playlist "New Year's Music":
			1. I Like To Move It
			2. Vivaldi Springs
			3. Beethoven's Symphony No. 5
			4. Auld Lang Syne */

		cout << endl << endl << "And Playlist 1 Again: " << endl;
		playlist1.Display();
		/*Expected Output:
		3 Songs in Playlist "Favorites":
			1. Ode to Joy
			2. Vivaldi Springs
			3. Beethoven's Symphony No. 5 */

		cout << endl << endl << "Playlist 3: " << endl;
		Playlist playlist3;
		cout << playlist3.GetName() << endl;//Should output Untitled
		playlist3 = playlist1;
		cout << playlist3.GetName() << endl;//Should output Favorites
		playlist3.SetName("Birthday Music");
		playlist3.AddSong("Happy Happy Birthday!");
		playlist3.AddSong("For He's a Jolly Good Fellow");
		playlist3.Display();
		/*Expected Output:
		5 Songs in Playlist "Birthday Music":
			1. Ode to Joy
			2. Vivaldi Springs
			3. Beethoven's Symphony No. 5
			4. Happy Happy Birthday!
			5. For He's a Jolly Good Fellow */

	
	
	return 0;
}