/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qblockswebview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVerify;
    QAction *actionUpload;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionSettings;
    QAction *actionNew_2;
    QAction *actionOpen_2;
    QAction *actionSave_2;
    QAction *actionUpload_2;
    QAction *actionPreferences;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionMessages;
    QAction *actionMonitor;
    QAction *actionShow_hide_monitor;
    QAction *action_export_sketch;
    QAction *actionSave_as;
    QAction *actionInclude;
    QAction *actionVerify_2;
    QAction *actionShow_hide_code;
    QAction *actionShow_hide_icon_labels;
    QAction *actionList_of_examples;
    QAction *actionExamples;
    QAction *actionGraph;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QBlocksWebView *webView;
    QWidget *widgetConsole;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *consoleEdit;
    QPushButton *consoleSendButton;
    QTextEdit *consoleText;
    QWidget *graphsWidget;
    QVBoxLayout *graphLayout;
    QWidget *messagesWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *messagesCloseButton;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *boardBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QComboBox *serialPortBox;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuExport_as_ino;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menu_Edit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *monitorToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(640, 480));
        actionVerify = new QAction(MainWindow);
        actionVerify->setObjectName(QStringLiteral("actionVerify"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/check_alt_24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVerify->setIcon(icon);
        actionUpload = new QAction(MainWindow);
        actionUpload->setObjectName(QStringLiteral("actionUpload"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/arrow_right_alt1_24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUpload->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/upload_18x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/download_18x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/document_alt_stroke_18x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon4);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/cog_24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon5);
        actionNew_2 = new QAction(MainWindow);
        actionNew_2->setObjectName(QStringLiteral("actionNew_2"));
        actionOpen_2 = new QAction(MainWindow);
        actionOpen_2->setObjectName(QStringLiteral("actionOpen_2"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QStringLiteral("actionSave_2"));
        actionUpload_2 = new QAction(MainWindow);
        actionUpload_2->setObjectName(QStringLiteral("actionUpload_2"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionMessages = new QAction(MainWindow);
        actionMessages->setObjectName(QStringLiteral("actionMessages"));
        actionMessages->setCheckable(true);
        actionMonitor = new QAction(MainWindow);
        actionMonitor->setObjectName(QStringLiteral("actionMonitor"));
        actionMonitor->setCheckable(true);
        actionMonitor->setChecked(false);
        actionMonitor->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/magnifying_glass_24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMonitor->setIcon(icon6);
        actionShow_hide_monitor = new QAction(MainWindow);
        actionShow_hide_monitor->setObjectName(QStringLiteral("actionShow_hide_monitor"));
        actionShow_hide_monitor->setCheckable(true);
        action_export_sketch = new QAction(MainWindow);
        action_export_sketch->setObjectName(QStringLiteral("action_export_sketch"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave_as->setEnabled(false);
        actionInclude = new QAction(MainWindow);
        actionInclude->setObjectName(QStringLiteral("actionInclude"));
        actionVerify_2 = new QAction(MainWindow);
        actionVerify_2->setObjectName(QStringLiteral("actionVerify_2"));
        actionShow_hide_code = new QAction(MainWindow);
        actionShow_hide_code->setObjectName(QStringLiteral("actionShow_hide_code"));
        actionShow_hide_icon_labels = new QAction(MainWindow);
        actionShow_hide_icon_labels->setObjectName(QStringLiteral("actionShow_hide_icon_labels"));
        actionShow_hide_icon_labels->setCheckable(true);
        actionShow_hide_icon_labels->setChecked(false);
        actionList_of_examples = new QAction(MainWindow);
        actionList_of_examples->setObjectName(QStringLiteral("actionList_of_examples"));
        actionExamples = new QAction(MainWindow);
        actionExamples->setObjectName(QStringLiteral("actionExamples"));
        actionGraph = new QAction(MainWindow);
        actionGraph->setObjectName(QStringLiteral("actionGraph"));
        actionGraph->setCheckable(true);
        actionGraph->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/bar-chart-24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGraph->setIcon(icon7);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, 0, 9, 0);
        webView = new QBlocksWebView(layoutWidget);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(webView);

        widgetConsole = new QWidget(layoutWidget);
        widgetConsole->setObjectName(QStringLiteral("widgetConsole"));
        widgetConsole->setMinimumSize(QSize(0, 100));
        verticalLayout_2 = new QVBoxLayout(widgetConsole);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        consoleEdit = new QLineEdit(widgetConsole);
        consoleEdit->setObjectName(QStringLiteral("consoleEdit"));

        horizontalLayout_3->addWidget(consoleEdit);

        consoleSendButton = new QPushButton(widgetConsole);
        consoleSendButton->setObjectName(QStringLiteral("consoleSendButton"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/enter-16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        consoleSendButton->setIcon(icon8);

        horizontalLayout_3->addWidget(consoleSendButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        consoleText = new QTextEdit(widgetConsole);
        consoleText->setObjectName(QStringLiteral("consoleText"));
        consoleText->setFrameShape(QFrame::StyledPanel);
        consoleText->setLineWidth(1);
        consoleText->setReadOnly(true);
        consoleText->setAcceptRichText(false);

        verticalLayout_2->addWidget(consoleText);

        graphsWidget = new QWidget(widgetConsole);
        graphsWidget->setObjectName(QStringLiteral("graphsWidget"));
        sizePolicy.setHeightForWidth(graphsWidget->sizePolicy().hasHeightForWidth());
        graphsWidget->setSizePolicy(sizePolicy);
        graphLayout = new QVBoxLayout(graphsWidget);
        graphLayout->setSpacing(6);
        graphLayout->setContentsMargins(11, 11, 11, 11);
        graphLayout->setObjectName(QStringLiteral("graphLayout"));
        graphLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(graphsWidget);


        horizontalLayout_4->addWidget(widgetConsole);

        splitter->addWidget(layoutWidget);
        messagesWidget = new QWidget(splitter);
        messagesWidget->setObjectName(QStringLiteral("messagesWidget"));
        messagesWidget->setMinimumSize(QSize(0, 100));
        verticalLayout = new QVBoxLayout(messagesWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 0, 9, 0);
        frame = new QFrame(messagesWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 30));
        frame->setStyleSheet(QLatin1String("border: 0px;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(760, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        messagesCloseButton = new QToolButton(frame);
        messagesCloseButton->setObjectName(QStringLiteral("messagesCloseButton"));
        messagesCloseButton->setStyleSheet(QLatin1String("font-weight: bold;\n"
"color: #E47128;\n"
"border: none;\n"
"hover: { border: 1px };\n"
"pressed: { border: 1px };"));
        messagesCloseButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(messagesCloseButton);


        verticalLayout->addWidget(frame);

        textBrowser = new QTextBrowser(messagesWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(1);

        verticalLayout->addWidget(textBrowser);

        splitter->addWidget(messagesWidget);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 4, 9, 4);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/chip-micro-24x24.png")));

        horizontalLayout->addWidget(label);

        boardBox = new QComboBox(centralWidget);
        boardBox->setObjectName(QStringLiteral("boardBox"));

        horizontalLayout->addWidget(boardBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/usb-24x24.png")));

        horizontalLayout->addWidget(label_2);

        serialPortBox = new QComboBox(centralWidget);
        serialPortBox->setObjectName(QStringLiteral("serialPortBox"));
        serialPortBox->setMinimumSize(QSize(0, 0));
        serialPortBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(serialPortBox);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuExport_as_ino = new QMenu(menu_File);
        menuExport_as_ino->setObjectName(QStringLiteral("menuExport_as_ino"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);
        monitorToolBar = new QToolBar(MainWindow);
        monitorToolBar->setObjectName(QStringLiteral("monitorToolBar"));
        monitorToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, monitorToolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu_File->addAction(actionNew_2);
        menu_File->addSeparator();
        menu_File->addAction(actionOpen_2);
        menu_File->addAction(actionInclude);
        menu_File->addAction(actionExamples);
        menu_File->addSeparator();
        menu_File->addAction(actionSave_2);
        menu_File->addAction(actionSave_as);
        menu_File->addAction(menuExport_as_ino->menuAction());
        menu_File->addSeparator();
        menu_File->addAction(actionVerify_2);
        menu_File->addAction(actionUpload_2);
        menu_File->addSeparator();
        menu_File->addAction(actionPreferences);
        menu_File->addSeparator();
        menu_File->addAction(actionQuit);
        menuExport_as_ino->addAction(action_export_sketch);
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionMessages);
        menuView->addAction(actionShow_hide_monitor);
        menuView->addAction(actionShow_hide_code);
        menuView->addAction(actionShow_hide_icon_labels);
        menuView->addSeparator();
        menuView->addAction(actionZoomIn);
        menuView->addAction(actionZoomOut);
        menu_Edit->addAction(actionUndo);
        menu_Edit->addAction(actionRedo);
        mainToolBar->addAction(actionVerify);
        mainToolBar->addAction(actionUpload);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNew);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSettings);
        mainToolBar->addAction(actionMonitor);
        monitorToolBar->addAction(actionGraph);
        monitorToolBar->addAction(actionMonitor);

        retranslateUi(MainWindow);
        QObject::connect(actionVerify, SIGNAL(triggered()), MainWindow, SLOT(actionVerify()));
        QObject::connect(actionUpload, SIGNAL(triggered(bool)), MainWindow, SLOT(actionUpload()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(actionOpen()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(actionSave()));
        QObject::connect(actionNew, SIGNAL(triggered()), MainWindow, SLOT(actionNew()));
        QObject::connect(actionSettings, SIGNAL(triggered()), MainWindow, SLOT(actionSettings()));
        QObject::connect(actionNew_2, SIGNAL(triggered()), MainWindow, SLOT(actionNew()));
        QObject::connect(actionOpen_2, SIGNAL(triggered()), MainWindow, SLOT(actionOpen()));
        QObject::connect(actionUpload_2, SIGNAL(triggered()), MainWindow, SLOT(actionUpload()));
        QObject::connect(actionPreferences, SIGNAL(triggered()), MainWindow, SLOT(actionSettings()));
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(actionQuit()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(actionAbout()));
        QObject::connect(messagesCloseButton, SIGNAL(clicked()), MainWindow, SLOT(actionCloseMessages()));
        QObject::connect(actionMessages, SIGNAL(triggered()), MainWindow, SLOT(actionMessages()));
        QObject::connect(actionMonitor, SIGNAL(triggered()), MainWindow, SLOT(actionMonitor()));
        QObject::connect(actionShow_hide_monitor, SIGNAL(triggered()), MainWindow, SLOT(actionMonitor()));
        QObject::connect(consoleSendButton, SIGNAL(clicked()), MainWindow, SLOT(actionMonitorSend()));
        QObject::connect(consoleEdit, SIGNAL(returnPressed()), MainWindow, SLOT(actionMonitorSend()));
        QObject::connect(actionSave_2, SIGNAL(triggered()), MainWindow, SLOT(actionSave()));
        QObject::connect(boardBox, SIGNAL(currentIndexChanged(QString)), MainWindow, SLOT(onBoardChanged()));
        QObject::connect(action_export_sketch, SIGNAL(triggered()), MainWindow, SLOT(actionExportSketch()));
        QObject::connect(actionSave_as, SIGNAL(triggered()), MainWindow, SLOT(actionSaveAs()));
        QObject::connect(actionVerify_2, SIGNAL(triggered()), MainWindow, SLOT(actionVerify()));
        QObject::connect(actionInclude, SIGNAL(triggered()), MainWindow, SLOT(actionInclude()));
        QObject::connect(actionShow_hide_code, SIGNAL(triggered()), MainWindow, SLOT(actionCode()));
        QObject::connect(actionShow_hide_icon_labels, SIGNAL(triggered()), MainWindow, SLOT(actionIconLabels()));
        QObject::connect(actionExamples, SIGNAL(triggered()), MainWindow, SLOT(actionExamples()));
        QObject::connect(actionGraph, SIGNAL(triggered()), MainWindow, SLOT(actionGraph()));
        QObject::connect(actionZoomIn, SIGNAL(triggered()), MainWindow, SLOT(actionZoomIn()));
        QObject::connect(actionZoomOut, SIGNAL(triggered()), MainWindow, SLOT(actionZoomOut()));
        QObject::connect(actionUndo, SIGNAL(triggered()), MainWindow, SLOT(actionDocumentUndo()));
        QObject::connect(actionRedo, SIGNAL(triggered()), MainWindow, SLOT(actionDocumentRedo()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Facilino", 0));
        actionVerify->setText(QApplication::translate("MainWindow", "Verify", 0));
#ifndef QT_NO_TOOLTIP
        actionVerify->setToolTip(QApplication::translate("MainWindow", "Verify", 0));
#endif // QT_NO_TOOLTIP
        actionVerify->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        actionUpload->setText(QApplication::translate("MainWindow", "Upload", 0));
#ifndef QT_NO_TOOLTIP
        actionUpload->setToolTip(QApplication::translate("MainWindow", "Upload", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionNew_2->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen_2->setText(QApplication::translate("MainWindow", "Open...", 0));
        actionOpen_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save...", 0));
        actionSave_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionUpload_2->setText(QApplication::translate("MainWindow", "Upload", 0));
        actionUpload_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionPreferences->setShortcut(QApplication::translate("MainWindow", "Ctrl+,", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionMessages->setText(QApplication::translate("MainWindow", "Show/hide messages", 0));
        actionMonitor->setText(QApplication::translate("MainWindow", "Monitor", 0));
#ifndef QT_NO_TOOLTIP
        actionMonitor->setToolTip(QApplication::translate("MainWindow", "Monitor", 0));
#endif // QT_NO_TOOLTIP
        actionShow_hide_monitor->setText(QApplication::translate("MainWindow", "Show/hide monitor", 0));
        actionShow_hide_monitor->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+M", 0));
        action_export_sketch->setText(QApplication::translate("MainWindow", "Sketch (.ino)", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionInclude->setText(QApplication::translate("MainWindow", "Include...", 0));
#ifndef QT_NO_TOOLTIP
        actionInclude->setToolTip(QApplication::translate("MainWindow", "Include", 0));
#endif // QT_NO_TOOLTIP
        actionVerify_2->setText(QApplication::translate("MainWindow", "Verify", 0));
        actionShow_hide_code->setText(QApplication::translate("MainWindow", "Show/hide code", 0));
        actionShow_hide_icon_labels->setText(QApplication::translate("MainWindow", "Show/hide icon labels", 0));
        actionList_of_examples->setText(QApplication::translate("MainWindow", "List of examples", 0));
        actionExamples->setText(QApplication::translate("MainWindow", "Examples...", 0));
        actionGraph->setText(QApplication::translate("MainWindow", "Graph", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "Zoom +", 0));
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "Zoom -", 0));
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        consoleSendButton->setText(QString());
        messagesCloseButton->setText(QApplication::translate("MainWindow", "X", 0));
        label->setText(QString());
        boardBox->clear();
        boardBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "arduino:avr:uno", 0)
         << QApplication::translate("MainWindow", "arduino:avr:nano:cpu=atmega328", 0)
         << QApplication::translate("MainWindow", "arduino:avr:mega", 0)
         << QApplication::translate("MainWindow", "arduino:avr:diecimila", 0)
         << QApplication::translate("MainWindow", "arduino:avr:bt", 0)
         << QApplication::translate("MainWindow", "Intel:arc32:arduino_101", 0)
         << QApplication::translate("MainWindow", "esp8266:esp8266:generic:CpuFrequency=80,FlashFreq=40,FlashMode=dio,UploadSpeed=115200,FlashSize=512K64,ResetMethod=ck,Debug=Disabled,DebugLevel=None____", 0)
         << QApplication::translate("MainWindow", "esp8266:esp8266:nodemcuv2:CpuFrequency=80,UploadSpeed=115200,FlashSize=4M3M", 0)
        );
        label_2->setText(QString());
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuExport_as_ino->setTitle(QApplication::translate("MainWindow", "Export as...", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "&Tools", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        monitorToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
