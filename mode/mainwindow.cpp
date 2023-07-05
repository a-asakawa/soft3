#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QThread>
#include <QTimer>


std::string result_path1, error;//結果表示画面の画像ファイルパスとエラーのときに何かしらの文字列をを入れてもらうやつ
#define RESULT_PATH "/home/user/Qt/testresult.png"
#define ERRORcheck "error01"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("間違い撲滅委員会〜打倒サイゼリ○〜"));

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_select_cheat_released()
{
    ui->stackedWidget->setCurrentIndex(2); //発表準備中の画面に飛んでから処理できるようにしたい
    //QTimer::singleShot(2000,this);
    //QThread::sleep(2); 遷移する前の画面で止まっちゃう


    //error = ERRORcheck; //エラー判断用のグローバル変数を作成し、エラーの場合はそこに何かしらの文字列を入れてもらうようにしたい（今回は"error01"）
    QString Qerror = QString::fromStdString(error); //受け取った文字列を変換

    if(Qerror.compare(ERRORcheck, Qt::CaseSensitive) == 0 ){
        ui->stackedWidget->setCurrentIndex(3); //受け取った文字列が予め決めていた文字列と一致した場合、エラー画面に遷移
    }
    else{
        //結果を表示する前に、2秒ほど会議中の画面を入れたほうがいいかなと思ったのでいれました！

        QTimer::singleShot(3000,this, SLOT(screen_transition()));

    }

}

void MainWindow::screen_transition()
{
    //time.stop();
//    auto mp = new QMediaPlayer();
//    mp->setMedia(QUrl::fromLocalFile("/home/user/Qt/ジャン！.mp3"));
//    mp->setVolume(30);
//    mp->play();
    ui->stackedWidget->setCurrentIndex(4); //結果表示画面に遷移
    result_path1 = RESULT_PATH; //受け取ったパス(仮)を代入
    QString Qresult_path = QString::fromStdString(result_path1); //受け取ったパスを変換
    QPixmap pix(Qresult_path);
    ui->result->setPixmap(pix);
}




void MainWindow::on_select_jiriki_released()
{
    ui->stackedWidget->setCurrentIndex(1);//自力モードへ
}
