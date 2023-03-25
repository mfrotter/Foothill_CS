// Student ID: 20504093
// TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//
#include <iostream>
#include <sstream>
using namespace std;
// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
string rotate_vowels(string& s)
{
   for (size_t i = 0; i < s.length(); i++)
   {
      if (s[i] == 'a')
         s[i] = 'e';
      else if (s[i] == 'e')
         s[i] = 'i';
      else if (s[i] == 'i')
         s[i] = 'o';
      else if (s[i] == 'o')
         s[i] = 'u';
      else if (s[i] == 'u')
         s[i] = 'a';
   }

   return s;
}

// Return a string in which all occurrences of s have been replaced by th
string lispify(string s)
{
   for (size_t i = 0; i < s.length(); i++)
   {
      if (s[i] == 's')
         {
         s[i] = 't';
         s.insert(i+1, 1, 'h');
         }
      if (s[i] == 'S')
         {
         s[i] = 'T';
         s.insert(i+1, 1, 'h');
         }
   }

   string s2 = s;

   return s2;

}

// Enter the user-interaction loop as described earlier
void enter()
{
   int hello;
   string userString, userString2, word;
   cout << "What?" << endl;
   while(1)
   {
      hello = 0;
      getline(cin, userString);
      istringstream(userString) >> userString2;

      if(userString2 == "")
      {
         cout << "What?" << endl;
         continue;
      }

      cout << "    " << userString << endl << endl;

      for (size_t i = 0; i < userString.length(); i++ )
      {
         if(userString[i] == '!')
         {
            cout << "OMG! You don't say!! " << userString << "!!!!!" << endl;
            hello = 1;
            break;
         }
      }

      if (hello == 1)
      continue;

      stringstream iss(userString);
      while (iss >> word)
      {
         if (word == "why" || word == "Why" || word == "What" || word == "what")
         {
            cout << "I'm sorry, I don't like questions that contain what or why." << endl;
            hello = 1;
            break;
         }

      }

      if (hello == 1)
      continue;

      for (size_t i = 0; i < userString.length(); i++ )
      {
         if(userString[i] == 's' || userString[i] == 'S')
         {
            cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl;
            cout << lispify(userString) << "! Sheesh! Now what?" << endl;
            hello = 1;
            break;
         }
      }

      if (hello == 1)
      continue;

      if (userString == "quit" || userString == "Quit" || userString == "bye" || userString == "Bye")
      {
         cout << "Ok Bye. Nice being a force of change in your life." << endl;
         break;
      }

      int randomAnswer = rand() % 10;
      if (randomAnswer == 8 || randomAnswer == 9)
      {
         cout << "Huh? Why do you say: " << userString << "?" << endl;
      }
      else
      {
         cout << rotate_vowels(userString) << "?" << endl;
      }
   }
}

//int main()
//{
//   enter();
//}
