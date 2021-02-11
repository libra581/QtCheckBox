# Кастомный CheckBox (флажок)

В рамках проекта создания и сравнения сценариев экспертной системы необходимо было реализовать кастомный флажок.
Кастомный CheckBox представляет собой класс наследованный от *QCheckBox*. Позволяет задавать свои цвета background'a,
которые плавно сменяют друг друга при нажатии на объект флажка.<br>

Плафторма: ОС Windows

# Использование
В конструкторе класса myCheckBox необходимо задать *список цветов* (начальный и конечный цвет):<br>

```cpp 
#define stClr QColor(200, 200, 0)
#define endClr QColor(200, 50, 200)

QList<QColor> colors;
colors << stClr << endClr;

myCheckBox *chk_box = new myCheckBox(colors, &parent_wdg);
```

При этом обявление конструктора myCheckBox класса выглядит так:

```cpp 
myCheckBox(QList<QColor> &colors, QWidget *parent = nullptr);
```

Структура CSS кода изменения цвета объекта имеет следующий вид:

```css
*{
  max-width:14px;
  height:14px; background-color: rgb(%1, %2, %3);
  border: 3px solid rgb(%1, %2, %3);
}
  
QCheckBox::indicator 
{
  border: 0px solid #5A5A5A;
  image: url(:/img/%1);
}
```
где "%n" = n-ый аргумент вставки через метод QString::arg().

# Скриншоты
![check_box_work](https://i.pinimg.com/originals/72/40/b6/7240b6aee07804973307a16a6c615c47.gif)
