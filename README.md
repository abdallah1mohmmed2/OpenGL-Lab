# OpenGL-Lab

بيئة تجارب C++ / OpenGL تعمل داخل GitHub Codespaces باستخدام Ubuntu وDesktop Lite.

## 1) فتح بيئة التطوير

1. افتح المستودع ثم اختر **Code → Codespaces → Create codespace on main**.
2. انتظر اكتمال إعداد الحاوية وتثبيت الحزم.
3. من تبويب **Ports** افتح المنفذ 6080 في المتصفح لعرض سطح المكتب.

## 2) ترجمة وتشغيل أول تجربة

من الطرفية داخل Codespace:

```bash
g++ main.cpp -o app -lglut -lGLU -lGL
DISPLAY=:1 ./app
```

يفتح البرنامج نافذة تعرض مثلثًا ملونًا. إذا لم تظهر النافذة، تحقق من أن Desktop Lite يعمل وأن متغير DISPLAY يساوي `:1`.

## 3) حفظ صورة للشاشة

بعد تشغيل البرنامج:

```bash
DISPLAY=:1 xwd -root -silent -out screenshot.xwd
convert screenshot.xwd screenshot.png
```

إذا لم يتوفر الأمر `convert`:

```bash
sudo apt-get install -y imagemagick
```

## 4) تسجيل فيديو للشاشة

شغّل البرنامج أولًا، ثم في طرفية ثانية:

```bash
ffmpeg -y -f x11grab -video_size 1280x800 -framerate 30 -i :1.0 -t 10 recording.mp4
```

عدّل الدقة والمدة حسب سطح المكتب. قد تختلف دقة Desktop Lite الفعلية؛ تحقق منها أو غيّر حجم سطح المكتب قبل التسجيل.

## الحزم المثبتة

- build-essential
- freeglut3-dev
- libglew-dev
- libglfw3-dev
- mesa-utils
- ffmpeg
- x11-apps

## ملاحظات

- هذه بيئة تجارب وليست خادم إنتاج.
- ملف `main.cpp` يستخدم GLUT/FreeGLUT لرسم مثلث ملون بسيط.
- `desktop-lite` يوفر سطح مكتب عبر المتصفح؛ قد تحتاج إلى فتح منفذ 6080 يدويًا من تبويب Ports.
- لم يتم تشغيل Codespace أو تنفيذ الترجمة من داخل GitHub بواسطة هذا الإعداد؛ يجب التحقق من نجاحها بعد فتح البيئة.
