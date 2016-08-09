#include "../api/telegram.hpp"

telegram::telegram()
{
	this->bot_id = "253746878:AAG3q_-b_kLMZdckRrSgJLtrQIoR3_YLlpw";
	//this->chat_id = "220868168";
}

int telegram::updates(string action)
{
	stringstream url;
	url << "https://api.telegram.org/bot" << this->bot_id << "/" << action;

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl)
	{
		const int timeout = 30000;

		curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322; .NET CLR 2.0.5");
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout/1000);

		res = curl_easy_perform(curl);
		
		if(CURLE_OK != res)
		{
			printf("Error: %s\n", strerror(res));
			return -1;
		}

		curl_easy_cleanup(curl);
		
		return 1;
	}
	return 0;
}

int telegram::me(string action)
{
	stringstream url;
	url << "https://api.telegram.org/bot" << this->bot_id << "/" << action;

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl)
	{
		const int timeout = 30000;

		curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322; .NET CLR 2.0.5");
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout/1000);

		res = curl_easy_perform(curl);
		
		if(CURLE_OK != res)
		{
			printf("Error: %s\n", strerror(res));
			return -1;
		}

		curl_easy_cleanup(curl);
		
		return 1;
	}
	return 0;
}

int telegram::getMe()
{
	return this->me("getMe");
}

int telegram::getUpdates()
{
	return this->updates("getUpdates");
}