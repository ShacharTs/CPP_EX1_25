<div dir="rtl">

# מטלה מספר 1 - מימוש גרף על ידי רשימת שכנויות

### יושרה אקדמית

במהלך העבודה על המטלות, מותר להתייעץ עם סטודנטים אחרים ולחפש מידע באינטרנט. עם זאת, חל איסור להעתיק קטעי קוד שלמים ממקורות חיצוניים, כולל סטודנטים אחרים, אתרי אינטרנט ומודלי בינה מלאכותית (כגון ChatGPT).

יש לדווח על כל עזרה שקיבלתם, בין אם מדובר בהתייעצות עם סטודנטים אחרים או במידע שנמצא באינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).
במקרה של שימוש בכלי בינה מלאכותית (AI), יש לצרף את הפרומפטים שהוזנו ואת התשובות שהתקבלו.

-----
* **מטרת המטלה:** הבנת החומר הנלמד בהרצאות הראשונות, כגון: ניהול זיכרון ב ++C, מחלקות, עצמים, מרחבי שמות, העברת פרמטרים לפונקציות, החזרת אובייקטים.
* **שימו לב!** במטלה **אסור** להשתמש בספרייה הסטנדרטית; ניתן להשתמש במערך. **יתכן שתצטרכו לממש מבנה/י נתונים המתאים לצרכי המטלה**. 
* **ההגשה ביחידים**.

---

## הוראות הגשה:

ב-Moodle יש להגיש קובץ טקסט המורכב מ-3 שורות:
  1. בשורה הראשונה – מספר תעודת הזהות.
  2. בשורה השנייה – קישור להגשה.
  3. בשורה השלישית – commit האחרון של הפרויקט.

---

גרפים הם חלק בלתי נפרד ממדעי המחשב. במהלך הלימודים נחשפתם לדרכים שונות לייצוג של גרפים (מטריצת שכנויות, רשימת שכנויות ועוד).

במטלה זו תממשו גרף באמצעות **רשימת שכנויות** – [Adjacency List](https://en.wikipedia.org/wiki/Adjacency_list).

---

## דרישות המטלה:

### מימוש המחלקות הבאות:
הוסיפו את המחלקות ב-namespaces משלהם. בקובץ הדמו, המימוש של הגרף נמצא במרחב ```graph``` והמימוש של האלגוריתמים נמצא במרחב ```algo```.

#### מחלקה בשם `Graph`:
הגרף יאותחל עם מספר קודקודים מסוים. הניחו שלא ניתן להוסיף\להוריד קודקודים.
המחלקה תכיל את רשימת השכנויות וכן את הפונקציות הבאות:
1. פונקציה  `addEdge`  מקבלת שלושה מספרים שלמים: מקור, יעד ומשקל (ברירת המחדל למשקל היא 1). הפונקציה תוסיף צלע (לא מכוונת) לגרף.
2. פונקציה  `removeEdge` מקבלת שני מספרים שלמים המייצגים צלע ומוחקת אותה מהגרף. אם הצלע לא קיימת, הפונקציה תזרוק חריגה.
3. פונקציה  `print_graph` מדפיסה את הגרף בצורה כלשהי הגיונית לבחירתכם.
4. במידת הצורך, ניתן להוסיף בנאים\פונקציות עזר רלונטיות למחלקה.

#### מחלקה בשם `Algorithms`:
המחלקה תכיל את הפונקציות הבאות:
1. פונקציה `bfs` – מקבלת גרף וקודקוד התחלה ומחזירה גרף שהוא עץ BFS (המתחיל מקודקוד ההתחלה).
2. פונקציה `dfs` – מקבלת גרף וקודקוד התחלה ומחזירה יער עצים המתקבל לפי סריקת DFS (המתחילה מקודקוד ההתחלה).
3. פונקציה `dijkstra` – מקבלת גרף, קודקוד התחלה וקודקוד יעד. הפונקציה תחזיר גרף המייצג את המסלול הקל ביותר בין שני הקודקודים.
4. פונקציה `has_cycle` – מקבלת גרף ומחזירה אמת אם ורק אם הגרף מכיל מעגל.
5. פונקציה `mst` – מקבלת גרף, מחשבת את העץ הפורש המינימלי ומחזירה אותו. לצורך המימוש, ניתן להיעזר באלגוריתם prim או kruskal.

 
---

#### דרישות נוספות:
- יש לבדוק את תקינות הקלט ולזרוק חריגות מתאימות במידת הצורך.
- יש לכתוב בדיקות יחידה עבור כל הפונקציות.
- מצורף קובץ בשם `Test.cpp` להדגמת מימוש הבדיקות בעזרת ספריית `doctest`.
- לשימושכם הקישור הבא [doctest](https://github.com/doctest/doctest) בו תוכלו לראות דוגמאות נוספות לשימוש בסיפריה זו.
- מצורף קובץ בשם `Demo.cpp` המדגים את השימוש בקוד.
- יש לבדוק שאין זליגת זיכרון באמצעות `valgrind`.

#### קובץ `Makefile`:
צרו קובץ `Makefile` הכולל את הפקודות הבאות:
- הפקודה `make Main` – להרצת קובץ ההדגמה.
- הפקודה `make test` – להרצת בדיקות היחידה.
- הפקודה `make valgrind` – בדיקת זליגת זיכרון באמצעות valgrind.

#### הנחיות נוספות:
- כתבו בתחילת **כל** קובץ את כתובת המייל שלכם.
- הגישו קובץ `README` המסביר את היררכיית המחלקות ובאילו ספריות השתמשתם.


בהצלחה!

</div>

