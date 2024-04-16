#include "include/mainwindow.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "include/simdjson.h"
#include "./ui_mainwindow.h"

using namespace simdjson;

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
    dom::parser parser;
    dom::element data;
    auto error = parser.load("../cards.json").get(data);
    if (error)
    {
        std::cerr << "Failed to parse JSON: " << error << std::endl;
        return;
    }
    data = data["data"];
    for (dom::element element : data)
    {
        std::string_view title = element["attributes"]["title"];
        ui->cardList->addItem(tr(title.data()));
    }
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_cardList_itemClicked(QListWidgetItem *item)
{
    std::string item_name = item->text().toStdString();
    dom::parser parser;
    dom::element data;
    auto error = parser.load("../cards.json").get(data);
    if (error)
    {
        std::cerr << "Failed to parse JSON: " << error << std::endl;
        return;
    }
    data = data["data"];
    for (dom::element element : data)
    {
        std::string_view title = element["attributes"]["title"];
        (void)title;
        // if (std::strstr(title.data(), item_name.c_str()))
            // ui->gridLayout->addItem();
    }
}


void MainWindow::on_dropFormat_currentIndexChanged(int index)
{
    ;
}


void MainWindow::on_searchField_textChanged()
{
    ui->cardList->clear();
    std::string searchText = ui->searchField->toPlainText().toStdString();
    dom::parser parser;
    dom::element data;
    auto error = parser.load("../cards.json").get(data);
    if (error)
    {
        std::cerr << "Failed to parse JSON: " << error << std::endl;
        return;
    }
    data = data["data"];
    for (dom::element element : data)
    {
        std::string_view title = element["attributes"]["title"];
        if (std::strstr(title.data(), searchText.c_str()))
            ui->cardList->addItem(tr(title.data()));
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
    dom::parser parser;
    dom::element data;
    auto error = parser.load("../cards.json").get(data);
    if (error)
    {
        std::cerr << "Failed to parse JSON: " << error << std::endl;
        return;
    }
    data = data["data"];
    for (dom::element element : data)
    {
        std::string_view title = element["attributes"]["title"];
        if (std::strstr(title.data(), searchText.c_str()))
            ui->cardList->addItem(tr(title.data()));
    }
}

