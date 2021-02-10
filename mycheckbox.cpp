#include "mycheckbox.h"
#include <QDebug>

myCheckBox::myCheckBox(QList<QColor> &colors, QWidget *parent /* = nullptr*/):
    QCheckBox(parent), m_start_color(colors.at(0)),
    m_end_color(colors.at(1)), m_name_icon_file(" "), m_animation(nullptr)
{
    this->installEventFilter(this);

    //Настрйока анимации изменения цвета CheckBox'a
    m_animation = new QPropertyAnimation(this, "color");
    m_animation->setDuration(1000);

    initColor();
}

//Функция setter цвета для QPropertyAnimation
void myCheckBox::setColor(QColor color)
{
     setStyleSheet(QString("*{max-width:14px;"
                           "height:14px; background-color: rgb(%1, %2, %3);").arg(color.red()).
                                                                 arg(color.green()).
                                                                 arg(color.blue())
                   + QString("border: 3px solid rgb(%1, %2, %3);}").arg(color.red() + 20).
                                                                   arg(color.green() + 20).
                                                                   arg(color.blue() + 20)
                               + "QCheckBox::indicator {"
                               "border: 0px solid #5A5A5A;"
                               +QString("image: url(:/img/%1);").arg(m_name_icon_file)+
                                "}");
}

//Функция getter цвета для QPropertyAnimation
QColor myCheckBox::color()
{
   return QColor(200, 200, 0);
}

//Обработчик событий CheckBox'a
bool myCheckBox::eventFilter(QObject *target, QEvent *event)
{
  //Обработка события, если произошло с чек боксом
  if (target == this)
  {
      //Обработка события клика (отпуска) налюбую кнопку мыши
      if(event->type() == QEvent::MouseButtonRelease)
      {
           //Настройка и запуск анимации по плавной смене цвета
           if (QString::compare(m_name_icon_file,"checkmark.png", Qt::CaseSensitive) >= 0)
                m_name_icon_file = " ";
           else
                m_name_icon_file = "checkmark.png";

           m_animation->setStartValue(m_start_color);
           m_animation->setEndValue(m_end_color);

           m_animation->start();

           m_temp_color = m_start_color;
           m_start_color = m_end_color;
           m_end_color = m_temp_color;
      }
  }

  return QCheckBox::eventFilter(target, event);
}

myCheckBox::~myCheckBox()
{
    if(m_animation != nullptr)
        delete m_animation;
}

//Первоначальная настройка цвета checkbox'a
void myCheckBox::initColor()
{
    setStyleSheet(QString("*{max-width:14px;"
                          "height:14px;"
                          "background-color: rgb(%1, %2, %3);").arg(m_start_color.red()).
                                                                arg(m_start_color.green()).
                                                                arg(m_start_color.blue())
                  + QString("border: 3px solid rgb(%1, %2, %3);}").arg(m_start_color.red()+20).
                                                                  arg(m_start_color.green()+20).
                                                                  arg(m_start_color.blue()+20)
                  + "QCheckBox::indicator {"
                       "border: 0px solid #5A5A5A;"
                      "image: url(:/img/);"

                           "}");
}
