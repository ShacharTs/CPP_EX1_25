<div dir="rtl">

#  מטלה מספר 1 - מימוש גרף על ידי רשימת שכנויות  
* מטרת המטלה - הבנת החומר הנלמד בהרצאות הראשונות כגון: ניהול זכרון, מחלקות, עצמים ,מרחבי שמות.
* הגשה ביחידים
* - ב-Moodle יש להגיש קובץ טקסט המורכב מ-3 שורות: בשורה הראשונה מספר תעודת הזהות שלכם, בשורה השנייה הקישור להגשה שלכם ובשורה השלישית הקומיט האחרון של הפרויקט.
 

גרפים הם חלק בילתי נפרד ממדעי המחשב. במהלך הלימודים נחשפתם לדרכים שונות לייצוג של גרפים (מטריצת שכנויות, רשימת שכנויות ועוד).

במטלה הזאת תייצגו גרף בעזרת **רשימת שכנויות** - https://en.wikipedia.org/wiki/Adjacency_list 



עליכם לממש את המחלקות עם המתודות הבאות:

מחלקה בשם ``Graph`` המכילה את רשימת השכנויות וגם:
    - פונקציה ``addEdge`` - מקבלת 3 מספרים שלמים המייצגים: מקור, יעד ומשקל - המשקל הדיפולטיבי הוא 1. המתודה תוסיף צלע (לא מכוונת) לגרף.
    - פונקציה ``removeEdge`` - מקבלת 2 מספרים שלמים המייצגים צלע ומוחקת את הצלע מהגרף. במידה והצלע לא קיימת המתודה תדפיס הודעה למסך.
    - פונקציה ``print_graph`` - מדפיסה את הגרף בסדר הגיוני לבחירתכם.
  
* מחלקה בשם ``Algorithms`` המכילה:
    - פונקציה ``bfs_scan`` - מקבלת גרף וקודקוד התחלה ומדפיסה את הגרף לפי סריקת BFS.
    - פונקציה ``dfs_scan`` - מקבלת גרף וקודקוד התחלה ומדפיסה את הגרף לפי סריקת DFS.
    - פונקציה ``dijkstra_path`` - מקבלת גרף, קודקוד התחלה וקודקוד יעד ומדפיסה את המסלול הקצר ביותר בין 2 הקודקודים בעזרת אלגוריתם דייקסטרה.
    - פונקציה ``has_cycle`` -  מקבלת גרף ומחזירה אמת אם ורק אם הגרף מכיל מעגל.
    - פונקציה ``all_paths`` - מקבלת גרף ומחזירה גרף המכיל את המשקל של המסלולים הקלים ביותר בין כל זוג קודקודים. רמז - קראו על אלגוריתם Floyd Warshall.
    - פונקציה ``print_mst`` - מקבלת גרף, מחשבת את העץ הפורש המינימלי בגרף ומדפיסה אותו. רמז - קראו על אלגוריתם Prim ועל אלגוריתם Kruskal.
    - פונקציה ``has_negative_cycle`` - מקבלת גרף ומחזירה אמת אם ורק אם הגרף מכיל מעגל שלילי.

</div>
<div dir="rtl">

* יש לבדוק את תקינות הקלט ולזרוק חריגות במידת הצורך. 
* יש לכתוב בדיקות יחידה לכל הפונקציות שכתבתם
* - מצורף קובץ בשם ``Test.cpp`` לצורך הדגמה של מימוש הבדיקות בעזרת הספרייה ``doctest`` המצורפת עם הקוד.

- מצורף  קובץ בשם ``Demo.cpp`` המדגים את הקוד.

**שימו לב!** במטלה הזאת **אסור** להשתמש במבני נתונים של הספרייה הסטנדרטית! מבנה הנתונים היחיד שבו אתם יכולים להשתמש הוא מערך. 

* יש לבדוק שאין זליגת זיכרון בעזרת ``valgrind`` (ייתכן ותצטרכו להתקין במכונה).

- כתבו קובץ main שבו אתם מדגימים את הקוד שכתבתם. בנוסף, עליכם ליצור קובץ ``Makefile`` כאשר הפקודה ``make Main`` 
תריץ את הקובץ לדוגמה שכתבתם, הפקודה ``make test`` תריץ את בדיקות היחידה , והפקודה ``make valgrind`` תבדוק שאין זליגת זיכרון בעזרת valgrind.

- כמו כן, עליכם לכתוב בתחילת **כל** קובץ את המייל שלכם. עליכם להגיש קובץ ``README`` המסביר את ההיררכיה של המחלקות ובאילו ספריות השתמשתם. כמו כן, עליכם לכתוב בתחילת כל קובץ את המייל שלכם.



מותר להתייעץ עם סטודנטים אחרים או לחפש מידע באינטרנט; אסור להעתיק קטעי-קוד שלמים מסטודנטים אחרים, מהאינטרנט וממודלי בינה מלאכותית (למשל, chatGPT).
יש לדווח על כל עזרה שקיבלתם, מסטודנטים אחרים או מהאינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).

בהצלחה!
</div>
