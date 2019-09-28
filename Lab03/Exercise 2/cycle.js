let current = 1;
function changePic(change){
  current += change;
  if(current > 5){
    current = 1;
  }else if(current < 1){
    current = 5;
  }
  document.getElementsByName("picture")[0].src = ("pictures/picture" + current + ".jpeg");
}
