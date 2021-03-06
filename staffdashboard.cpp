#include "staffdashboard.h"

StaffDashboard::StaffDashboard(StaffMember *s,QWidget *parent,bool fromAdmin):QWidget(parent){
    this->s = *s;
    container = new QWidget();
    mainLayout = new QVBoxLayout();
    _mainLayout = new QHBoxLayout();
    academicLayout=new QVBoxLayout();
    personalLayout=new QVBoxLayout();
    personalWidget = new QWidget();
    academicWidget = new QWidget();
    t1 = new QHBoxLayout();
    t2 = new QHBoxLayout();
    tabWidget = new QTabWidget();
    firstLabel = new QLabel("First Name: ",this);
    lastLabel = new QLabel("Last Name:",this);
    idLabel = new QLabel("ID: ",this);
    birthLabel = new QLabel("Graduation Year: ",this);
    gendreLabel = new QLabel("Gendre: ",this);
    piclbl1 = new QLabel(" ",this);
    piclbl2 = new QLabel(" ", this);
    graduationyearLabel = new QLabel("Graduation year: ",this);
    departmentLabel = new QLabel("Department: ",this);
    degreeLabel = new QLabel("Degree: ",this);

    fnameDBlbl = new QLabel(" ",this);
    lnameDBlbl = new QLabel(" ",this);
    departDBlbl = new QLabel(" ",this);
    degreeDBlbl = new QLabel(" ",this);
    gendreDBlbl = new QLabel(" ",this);
    birthDBlbl = new QLabel(" ",this);
    idDBlbl = new QLabel(" ",this);
    graduationyearLabelfromDatabase = new QLabel(" ",this);
    teachingcoursesLabelfromDatabase = new QLabel(" ",this);
    signout = new QPushButton("Signout");
    deleteBtn = new QPushButton("Delete");
    backBtn = new QPushButton("Back");
    editLastNametxt = new QLineEdit();
    editFirstNametxt = new QLineEdit();
    editBirthdatetxt = new QLineEdit();
    saveBtn = new QPushButton("Save");

    coursesAssignWidget = new QWidget();
    coursesAssignWidgetLay = new QVBoxLayout();
    coursesList = new QListWidget();
    saveCourse = new QPushButton("Save");


    fnameDBlbl->setFont(QFont("Cambria",12));
    lnameDBlbl->setFont(QFont("Cambria",12));
    birthDBlbl->setFont(QFont("Cambria",12));
    gendreDBlbl->setFont(QFont("Cambria",12));
    idDBlbl->setFont(QFont("Cambria",12));
    departDBlbl->setFont(QFont("Cambria",12));
    degreeDBlbl->setFont(QFont("Cambria",12));

    formlayout1 = new QFormLayout();
    formlayout1->setVerticalSpacing(50);
    formlayout1->setHorizontalSpacing(100);
    formlayout1->setFormAlignment(Qt::AlignCenter);

    formlayout2 = new QFormLayout();
    formlayout2->setVerticalSpacing(50);
    formlayout2->setHorizontalSpacing(100);
    formlayout2->setFormAlignment(Qt::AlignCenter);


    firstLabel->setFont(QFont("Times New Roman",17));
    lastLabel->setFont(QFont("Times New Roman",17));
    birthLabel->setFont(QFont("Times New Roman",17));
    gendreLabel->setFont(QFont("Times New Roman",17));
    idLabel->setFont(QFont("Times New Roman",17));

    degreeLabel->setFont(QFont("Times New Roman",17));
    graduationyearLabel->setFont(QFont("Times New Roman",17));
    departmentLabel->setFont(QFont("Times New Roman",17));

    coursesAssignWidget->setLayout(coursesAssignWidgetLay);
    coursesAssignWidgetLay->addWidget(coursesList);
    coursesAssignWidgetLay->addWidget(new QWidget);
    QHBoxLayout *lay2 = new QHBoxLayout();
    lay2->addWidget(new QWidget);
    lay2->addWidget(saveCourse);
    coursesAssignWidgetLay->addLayout(lay2);
    QStringList courses;
    for(Course c : Course::all()){
        courses.append(c.getName());
    }
    coursesList->addItems(courses);



    if(fromAdmin){
        formlayout1->addRow(firstLabel,editFirstNametxt);
        formlayout1->addRow(lastLabel,editLastNametxt);
        formlayout1->addRow(gendreLabel,gendreDBlbl);
        formlayout1->addRow(birthLabel,editBirthdatetxt);
    }else{
        formlayout1->addRow(firstLabel,fnameDBlbl);
        formlayout1->addRow(lastLabel,lnameDBlbl);
        formlayout1->addRow(gendreLabel,gendreDBlbl);
        formlayout1->addRow(birthLabel,birthDBlbl);
    }

    formlayout2->addRow(idLabel,idDBlbl);
    formlayout2->addRow(graduationyearLabel,graduationyearLabelfromDatabase);
    formlayout2->addRow(degreeLabel,degreeDBlbl);
    formlayout2->addRow(departmentLabel,departDBlbl);

    coursesList->setObjectName("login");
    coursesList->setStyleSheet(QString("QListWidget#login{border-radius : 20px; padding : 7px; ")+
                                       "font-weight: bold; font-size: 15px; border: 1px solid gray;}"+
                                       "QListView::item{padding : 10px}");
    coursesList->setMaximumHeight(350);
    coursesList->setAlternatingRowColors(true);
    coursesList->setSelectionMode(QAbstractItemView::MultiSelection);

    signout->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : blue;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    signout->setMinimumHeight(40);
    signout->setMaximumWidth(260);
    signout->setObjectName("login");


    editFirstNametxt->setMinimumHeight(40);
    editFirstNametxt->setMaximumWidth(260);
    editFirstNametxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    editFirstNametxt->setPlaceholderText("           First Name");
    editFirstNametxt->setAlignment(Qt::AlignCenter);

    editLastNametxt->setMinimumHeight(40);
    editLastNametxt->setMaximumWidth(260);
    editLastNametxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    editLastNametxt->setPlaceholderText("           Last Name");
    editLastNametxt->setAlignment(Qt::AlignCenter);

    editBirthdatetxt->setMinimumHeight(40);
    editBirthdatetxt->setMaximumWidth(260);
    editBirthdatetxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    editBirthdatetxt->setPlaceholderText("           Birthdate");
    editBirthdatetxt->setAlignment(Qt::AlignCenter);


    backBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : blue;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    backBtn->setMinimumHeight(40);
    backBtn->setMaximumWidth(260);
    backBtn->setObjectName("login");


    deleteBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                     "QPushButton#login{ background : red;}"+
                                     "QPushButton:hover#login{ background : #333333;}");
    deleteBtn->setMinimumHeight(40);
    deleteBtn->setMaximumWidth(260);
    deleteBtn->setObjectName("login");

    saveBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background :  #00c941;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    saveBtn->setMinimumHeight(40);
    saveBtn->setMaximumWidth(260);
    saveBtn->setObjectName("login");

    saveCourse->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background :  #00c941;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    saveCourse->setMinimumHeight(40);
    saveCourse->setMaximumWidth(260);
    saveCourse->setObjectName("login");

    fnameDBlbl->setText(s->getFirstName());
    lnameDBlbl->setText(s->getLastName());
    birthDBlbl->setText(s->getBirthDate());
    gendreDBlbl->setText(s->getGendre());
    piclbl1->setPixmap(QPixmap(s->getPicture()));
    piclbl2->setPixmap(QPixmap(s->getPicture()));
    idDBlbl->setText("S"+s->getCollegeId());
    departDBlbl->setText(s->getDepartment());
    degreeDBlbl->setText(s->getDegree());
    graduationyearLabelfromDatabase->setText(s->getBirthDate());

    piclbl1->setMaximumWidth(int(piclbl1->width()*200/piclbl1->width()));
    piclbl1->setMaximumHeight(int(piclbl1->height()*200/piclbl1->height()));
    piclbl1->setScaledContents(true);
    piclbl2->setMaximumWidth(int(piclbl2->width()*200/piclbl2->width()));
    piclbl2->setMaximumHeight(int(piclbl2->height()*200/piclbl2->height()));
    piclbl2->setScaledContents(true);

    QHBoxLayout *t0lay = new QHBoxLayout;
    if(!fromAdmin){
        t0lay->addWidget(new QWidget);
        t0lay->addWidget(signout,Qt::AlignRight);
    }else {
        t0lay->addWidget(backBtn);
        t0lay->addWidget(deleteBtn);
        t0lay->addWidget(new QWidget);
    }

    this->setLayout(_mainLayout);
    _mainLayout->addWidget(container);
    container->setLayout(mainLayout);
    mainLayout->addWidget(tabWidget);
    mainLayout->addLayout(t0lay);

    personalLayout->setAlignment(Qt::AlignLeft);
    personalWidget->setLayout(t1); //personal layout
    t1->addWidget(piclbl1);
    t1->addLayout(personalLayout);
    personalLayout->addLayout(formlayout1);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(new QWidget);
    lay->addWidget(saveBtn,Qt::AlignRight);
    if(fromAdmin)personalLayout->addLayout(lay);

    t1->setSpacing(30);

    //personalLayout->setSpacing(50);

    //academicLayout->setAlignment(Qt::AlignCenter);
    academicWidget->setLayout(t2); //academic layout
    t2->addWidget(piclbl2);
    t2->addLayout(academicLayout);
    academicLayout->addLayout(formlayout2);
    t2->setSpacing(30);

    tabWidget->addTab(personalWidget, " Personal ");
    if(fromAdmin)   tabWidget->addTab(coursesAssignWidget, " Assign Courses ");
    else{
        qDebug() << "length is : " << s->getCourses().length();
        for(Course c : s->getCourses() ){
            QWidget *courseWidget = new QWidget;
            QVBoxLayout *courseLay = new QVBoxLayout();
            courseWidget->setLayout(courseLay);
            QTableWidget *table = new QTableWidget;
            QVector<Student> students = Student::getByCourse(c.getName());
            table->setColumnCount(3);
            table->setHorizontalHeaderLabels(QStringList({"ID","Name","Department"}));
            table->setEditTriggers(QAbstractItemView::NoEditTriggers);
            table->setAlternatingRowColors(true);
            table->setColumnWidth(0,100);
            table->setColumnWidth(1,500);
            table->setColumnWidth(2,200);
            table->setRowCount(students.length());
            int a = 0;
            qDebug() << "Length here is " << students.length();
            for(Student s : students){
                table->setItem(a,0,new QTableWidgetItem(QString::number(s.getId())));
                table->setItem(a,1,new QTableWidgetItem(s.getFirstName()+" "+s.getLastName()));
                table->setItem(a,2,new QTableWidgetItem(s.getDepartment()));
                a++;
            }
            courseLay->addWidget(table);
            tabWidget->addTab(courseWidget," "+c.getName()+" ");
        }
    }

    tabWidget->setObjectName("login");
    tabWidget->setStyleSheet(QString("QTabWidget::pane#login{border: 1px solid gray;}")+
                                     "QTabBar::tab{padding : 8px;color : white;background : #666666; font-weight: bold;}"+
                                     "QTabBar::tab:selected{background : white; color : black}");


    this->setStyleSheet("background-color:white; border-radius : 10px;");
    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    editFirstNametxt->setText(s->getFirstName());
    editLastNametxt->setText(s->getLastName());
    editBirthdatetxt->setText(s->getBirthDate());

    connect(signout,&QPushButton::clicked,this,&StaffDashboard::onSignoutClicked);
    connect(backBtn, &QPushButton::clicked, this, &StaffDashboard::onBackClicked);
    connect(deleteBtn, &QPushButton::clicked, this, &StaffDashboard::onDeleteClicked);
    connect(saveBtn, &QPushButton::clicked, this, &StaffDashboard::onSaveClicked);
    connect(saveCourse, &QPushButton::clicked, this, &StaffDashboard::onSaveCoursesClicked);
}

void StaffDashboard::onSaveCoursesClicked(){
    for (QListWidgetItem *i : coursesList->selectedItems().toVector()){
        s.addCourse(i->text());
    }
    s.save();
    saveCourse->setEnabled(false);
    saveCourse->setText("Courses Assigned");
}

void StaffDashboard::onSaveClicked(){
    s.setFirstName(editFirstNametxt->text());
    s.setLastName(editLastNametxt->text());
    s.setBirthDate(editBirthdatetxt->text());
    s.save();
    saveBtn->setEnabled(false);
    saveBtn->setText("Data is Saved");
}

void StaffDashboard::onSignoutClicked(){
    emit Signout();
}
void StaffDashboard::onBackClicked(){
    qDebug() << "back";
    emit Back();
}
void StaffDashboard::onDeleteClicked(){
    qDebug() << "delete";
    s.delete1();
    emit Delete();
}
StaffDashboard::~StaffDashboard(){

}
