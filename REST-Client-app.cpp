#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/base_uri.h>

std::unique_ptr<web::http::client::http_client> client;

int main(int argc, char* argv[])
{
    client = std::unique_ptr<web::http::client::http_client>(new web::http::client::http_client(utility::conversions::to_string_t(argv[1])));

    auto task = client->request(utility::conversions::to_string_t("GET"), utility::conversions::to_string_t("api/v1/token"));
    task.wait();
    auto task2 = task.get().extract_json();
    task2.wait();

    auto output = task2.get().serialize();

    std::wcout << output;
}