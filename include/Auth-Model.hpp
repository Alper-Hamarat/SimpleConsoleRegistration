#include <string>

using namespace std;

//The path to the login file
static string filepath = "./";
//The name of the login file
static string filename = "login-credentials.txt";
//The location and filename to thefile
extern string fullPath;
/**
 * Helper function to match two texts
 * @param textOne The first text
 * @param textTwo The second text
 * @returns True if texts match false otherwise
 */
bool matchText(string textOne, string textTwo);

/**
 * Return password and username from username input.
 * @param username The username
 * @throws runtime_error
 * @returns Username and Password if username exists. Else an empty array
 */
array<string, 2> getLoginCredentials(string username);


/**
 * Add Login-Credentials to database.
 * @param username The username
 * @param password The password unhashed
 * @returns true if success
 *          false on failure
 */
bool addLoginCredentials(string username, string password);

/**
 * Check Login Credentials.
 * @param username The username
 * @param password The password unhashed
 * @returns true if success
 *          false on failure
 */
bool checkLoginCredentials(string username, string password);


/**
 * Check If username exists.
 * @param username The username
 * @returns true if success
 *          false on failure
 */
bool checkUsernameExists (string username);