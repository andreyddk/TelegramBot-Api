#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <json-c/json.h>

using namespace std;

class telegram
{
	private:
		int updates(string);
		int me(string);

	public:
		string bot_id;
		string chat_id;
		telegram();
		int getMe();
		int getUpdates();

};

class message : public telegram
{
	private:
		int send(string, string);

	public:
		message();
		int sendMessage(string, string);

};
