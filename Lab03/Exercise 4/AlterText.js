function updateText(){
  changeBackground();
  changeBorder();
}

function changeBackground(){
  let red = document.getElementsByName("red1")[0];
  let blue = document.getElementsByName("blue1")[0];
  let green = document.getElementsByName("green1")[0];
  let paragraph = document.getElementById("paragraph").style;
  rgbCorrection(red, green, blue, paragraph, false);
}

function changeBorder(){
  let red = document.getElementsByName("red2")[0];
  let blue = document.getElementsByName("blue2")[0];
  let green = document.getElementsByName("green2")[0];
  let paragraph = document.getElementById("table").style;
  rgbCorrection(red, green, blue, paragraph, true);
}

function rgbCorrection(red, green, blue, element, isBorder){
  if(red.value > 255){
    red.value = 255;
  }else if(red.value < 0){
    red.value = 0;
  }

  if(blue.value > 255){
    blue.value = 255;
  }else if(blue.value < 0){
    blue.value = 0;
  }

  if(green.value > 255){
    green.value = 255;
  }else if(green.value < 0){
    green.value = 0;
  }
  
  if(isBorder){
    element.borderColor = "rgb(" + red.value + ", " + green.value + ", " + blue.value + ")";
  }else{
    element.backgroundColor = "rgb(" + red.value + ", " + green.value + ", " + blue.value + ")";
  }
}
