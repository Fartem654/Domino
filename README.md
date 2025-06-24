<h1>Валидатор цепочки домино</h1>

<p>Проверка, можно ли выложить набор костей домино в цепочку по правилам.</p>

<nav ы>
  <ul>
    <li><a href="#description">Описание задачи</a></li>
    <li><a href="#features">Возможности программы</a></li>
    <li><a href="#checks">Проверки</a></li>
    <li><a href="#struct">Структура проекта</a></li>
    <li><a href="#screenshots">Скриншоты</a></li>
    <li><a href="#examples">Примеры работы</a></li>
    <li><a href="#performed">Выполнил</a></li>
  </ul>
</nav>

<h2 id="description"> Описание задачи</h2>

<p>Дано:</p>
<ul>
  <li>Набор костей домино (например, <code>"02 24 43 31 12 20"</code>)</li>
  <li>Каждая кость — это пара чисел от <code>0</code> до <code>6</code></li>
</ul>

<p>Необходимо:</p>
<ul>
  <li>Проверить, можно ли выложить все кости в цепочку так, чтобы соседние цифры совпадали</li>
  <li>Если можно — вывести один из возможных вариантов разложения</li>
  <li>Использовать двусвязный список для хранения результата</li>
</ul>

<h2 id="features"> Возможности программы</h2>

<ul>
  <li>Ввод через консоль</li>
  <li>Ввод из файла</li>
  <li>Случайная генерация набора</li>
</ul>

<h2 id="checks"> Проверки</h2>

<ul>
  <li>Формат ввода</li>
  <li>Диапазон чисел (от 0 до 6)</li>
  <li>Связность графа</li>
  <li>Не более двух вершин с нечётной степенью</li>
</ul>

<h2 id="struct">Структура проекта</h2>

<pre><code>
├── Domino.cpp
├── Domino.h

</code></pre>

<h2 id="examples">Примеры работы</h2>

<h3>Можно выложить</h3>

<p><strong>Входные данные:</strong> <code>02 24 43 31 12 20</code></p>

<p><strong>Результат:</strong> <code>02 20 02 24 43 31 12 24</code></p>

<h3>Нельзя выложить</h3>

<p><strong>Входные данные:</strong> <code>43 61 25 52 42 42 02 02 31 43</code></p>

<p><strong>Результат:</strong> <code>Некорректные входные данные.</code></p>

<h2 id="screenshots">Скриншоты</h2>

![image](https://github.com/user-attachments/assets/041b2aa6-9f57-4feb-9a00-dcfe74a0044f)

![image](https://github.com/user-attachments/assets/a35cbc7c-64be-48b4-8af5-edaed7fbc514)

![image](https://github.com/user-attachments/assets/13743fcc-8cce-46a8-bbc7-2e2d44144c79)


<h2 id="performed">Выполнил:</h2>

<p>Фадеев Артём ИТ-12</p>
