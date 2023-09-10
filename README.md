# Grey
<h2>Make your PNG file grey wirh using NASM or C algorithms</h2>
<p>
  Program works in x86-64 Linux, NASM assembler(Intel syntax)
</p>
<h3>
  To compile it:
</h3>
<p>
  <b>C realization:</b>
  <br>
  "make" in terminal
</p>
<p>
  <b>NASM realization:</b>
  <br>
  "make BODY=asm"
</p>
<p>
  <b>To add optimization</b>
  <br>
  "make OPT=ofast"
  <br>
  OPT can be equal "o0", "o1", "o2", "o3", "ofast"
</p>
<br><br>
<h3>To launch program:</h3>
<p>
  <b>In terminal(Linux):</b> ./grey picture.png result.png set_[one|two|three]
  <br>
  where picture.png - your image(PNG!), result.png - result image, set_one - algorithm
</p>
<hr>
<p>
  Luminance:<br>
  one: Gray = Red ∗ 0.3 + Green ∗ 0.59 + Blue ∗ 0.11<br>
  two: Gray = (Red ∗ 0.299 + Green ∗ 0.587 + Blue ∗ 0.114)<br>
  three: Gray = (Red ∗ 0.2126 + Green ∗ 0.7152 + Blue ∗ 0.0722)<br>
</p>

</p>
