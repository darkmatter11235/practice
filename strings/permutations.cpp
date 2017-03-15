#include <iostream>
#include <set>
using namespace std;

set<string> myFunction (const string& arg)
{
      // write the body of your function here
      //     set<string> perms;
      //         set<string>::iterator it;
      //             if ( arg.length() <= 1 ) { perms.insert(arg); return perms; }
      //                 char var = arg[0];
      //                     set<string> rperms = myFunction(arg.substr(1,arg.length()-1));
      //                             for(it = rperms.begin(); it != rperms.end(); it++) {
      //                                     string old_perm = *it;
      //                                              
      //                                                      int ol = old_perm.length();
      //                                                              for(int sit = 0; sit <= old_perm.length(); sit++) {
      //                                                                          string new_perm = old_perm.substr(0,sit)+var+old_perm.substr(sit, ol-sit);
      //                                                                                      perms.insert(new_perm);
      //                                                                                              }
      //                                                                                                  }
      //                                                                                                      return perms;
      //                                                                                                      }
      //
      //                                                                                                      int main ()
      //                                                                                                      {
      //                                                                                                          // run your function through some test cases here
      //                                                                                                              // remember: debugging is half the battle!
      //                                                                                                                 set<string> perms = myFunction ("bc");
      //                                                                                                                     set<string>::iterator it;
      //                                                                                                                         for(it = perms.begin(); it != perms.end(); it++) {
      //                                                                                                                                 cout << *it << endl;
      //                                                                                                                                     }
      //                                                                                                                                         return 0;
      //                                                                                                                                         }
