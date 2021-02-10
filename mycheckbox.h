/**************************************************************
 *
 *  Класс myCheckBox представляет собой кастомный объект QCheckBox,
 *  стиль которого меняется в соответсвии со структурой CSS кода.
 *
 *  Для возможности менять цвет в алгоритме применена анимация QPropertyAnimation
 *  и объявлен макрос Q_PROPERTY на свойство color.
 *
 **************************************************************
 * Программа выполнена в рамках заказа фриланс биржи KWORK.   *
 **************************************************************
 */

#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>
#include <QEvent>
#include <QPropertyAnimation>

class myCheckBox : public QCheckBox
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)

    QColor m_start_color;
    QColor m_end_color;
    QColor m_temp_color;
    QString m_name_icon_file;
    QPropertyAnimation *m_animation;

public:
    myCheckBox(QList<QColor> &colors, QWidget *parent = nullptr);

    void setColor (QColor color);
    QColor color();

    virtual bool eventFilter(QObject *target, QEvent *event) override;

    ~myCheckBox();

private:
    void initColor();
};

#endif // MYCHECKBOX_H
