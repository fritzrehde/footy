#include <stdio.h>
#include <curl/curl.h>

int get()
{
	CURL *curl;
	CURLcode response;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://calapi.inadiutorium.cz/api/v0/en/calendars/general-en/2021/03");

		response = curl_easy_perform(curl);

		if(response != CURLE_OK) {
			fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response));
		} else {
			printf("%c\n", response);
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
	return 0;
}
