/*************************************************
 *
 *  Наименование: Пользовательский (кастомный) СheckBox
 *  Версия: 1.0
 *  Дата написания: 01.05.2019
 *  Используемый язык: Qt/C++
 *  Написал: Семенов Д.С.
 *
 *  Описание цели программы:
 *  Программа демонстрирует работу с кастомным классом checkbox'a
 *  myCheckBox, который позволяет задавать свои цвета фона, использует
 *  кастомную картинку, а также плавно меняет цвета при клике.
 *
 *  Описание структуры программы:
 *  Для использования myCheckBox, необходимо
 *  при инициализации задать список из 2 цветов
 *  (1 - начальный цвет, 2 - конечный цвет).
 *
 *  Платформа: OC Windows
 *
 **************************************************************
 * Программа выполнена в рамках заказа фриланс биржи KWORK.   *
 **************************************************************
 */

#define stClr QColor(200, 200, 0)
#define endClr QColor(200, 50, 200)

#include <QApplication>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>

#include "mycheckbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget parent_wdg;

    QList<QColor> colors;
    colors << stClr << endClr;

    myCheckBox *chk_box = new myCheckBox(colors, &parent_wdg);

    QGridLayout *grid = new QGridLayout(&parent_wdg);
    grid->setMargin(5);
    grid->setSpacing(15);
    grid->addWidget(chk_box,1,1);

    parent_wdg.setLayout(grid);
    parent_wdg.show();

    return a.exec();
}
