#include "include/mainwindow.h"
#include "include/json.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "./ui_mainwindow.h"

using json = nlohmann::json;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // std::cout << std::filesystem::current_path().string() << '\n';
    ui->setupUi(this);

    // std::string curlRead;
    // auto curl = curl_easy_init();
    // if (curl)
    // {
    //     curl_easy_setopt(curl, CURLOPT_URL, "https://api-preview.netrunnerdb.com/api/v3/public/cards?page[limit]=9999");
    //     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    //     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlRead);
    //     curl_easy_perform(curl);
    //     curl_easy_cleanup(curl);
    // }
    // json data = json::parse(curlRead);
    std::ifstream json_input("../cards.json");
    json data;
    json_input >> data;
    data = data["data"];
    // std::cout << data["data"][0]["attributes"]["title"] << '\n';
    for (json& element: data)
    {
        std::string title = element["attributes"]["title"];
        // std::cout << title << '\n';
        ui->cardList->addItem(tr(title.c_str()));
    }
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_cardList_itemClicked(QListWidgetItem *item)
{
    item->text().toStdString();
}


void MainWindow::on_dropFormat_currentIndexChanged(int index)
{
    ;
}


void MainWindow::on_searchField_textChanged()
{
    ui->cardList->clear();
    std::string searchText = ui->searchField->toPlainText().toStdString();
    // std::cout << searchText << '\n';
    // std::string curlRead;
    // auto curl = curl_easy_init();
    // if (curl)
    // {
    //     curl_easy_setopt(curl, CURLOPT_URL, "https://api-preview.netrunnerdb.com/api/v3/public/cards?page[limit]=9999");
    //     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    //     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlRead);
    //     curl_easy_perform(curl);
    //     curl_easy_cleanup(curl);
    // }
    // json data = json::parse(curlRead);
    std::ifstream json_input("../cards.json");
    json data;
    json_input >> data;
    data = data["data"];
    for (json& element: data)
    {
        std::string title = element["attributes"]["title"];
        if (std::strstr(title.c_str(), searchText.c_str()))
            ui->cardList->addItem(tr(title.c_str()));
    }
}


void MainWindow::on_cardList_itemSelectionChanged()
{
    ;
}


void MainWindow::on_cardList_currentRowChanged(int currentRow)
{
    ;
}


void MainWindow::on_lineEdit_returnPressed()
{
    ui->cardList->clear();
    std::string searchText = ui->lineEdit->text().toStdString();
    // std::cout << searchText << '\n';
    // std::string curlRead;
    // auto curl = curl_easy_init();
    // if (curl)
    // {
    //     curl_easy_setopt(curl, CURLOPT_URL, "https://api-preview.netrunnerdb.com/api/v3/public/cards?page[limit]=9999");
    //     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    //     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlRead);
    //     curl_easy_perform(curl);
    //     curl_easy_cleanup(curl);
    // }
    // json data = json::parse(curlRead);
    std::ifstream json_input("../cards.json");
    json data;
    json_input >> data;
    data = data["data"];
    for (json& element: data)
    {
        std::string title = element["attributes"]["title"];
        if (std::strstr(title.c_str(), searchText.c_str()))
            ui->cardList->addItem(tr(title.c_str()));
    }
}

