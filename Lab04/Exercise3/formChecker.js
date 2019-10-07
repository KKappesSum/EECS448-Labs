window.onload = ()=>{
  document.getElementsByName("tacos")[0].value = 0;
  document.getElementsByName("burritos")[0].value = 0;
  document.getElementsByName("enchiladas")[0].value = 0;
}

function validatePass(){
  let email = document.getElementsByName("email")[0];
  let password = document.getElementsByName("password")[0];
  let validity = 0;

  if(email.value.includes("@") && email.value.includes(".")){
    console.log("Contains @ .");
    if((email.value.indexOf(".") - email.value.indexOf("@") > 2) && (email.value.indexOf(".") + 2 <= email.value.length - 1)){
      email.style = "border:solid black 2px";
      validity++;
      console.log("valid");
    }else{
      email.style = "border:solid red 2px";
      validity = 0;
    }
  }else{
    email.style = "border:solid red 2px";
    validity = 0;
  }
  if(password.value != "" && password.value != "undefined" && password.value != "\0"){
    password.style = "border:solid black 2px";
    validity++;
  }else{
    password.style = "border:solid red 2px";
    validity = 0;
  }

  if(validity == 2){
    document.getElementById("signIn").style = "display:none";
    document.getElementById("items").style = "display:block";
    document.getElementById("shipping").style = "display:block";
    document.getElementsByName("reset")[0].disabled = false;
    document.getElementsByName("submit")[0].disabled = false;
  }
}

function add(id, id2){
  document.getElementById(id).innerHTML++;
  document.getElementsByName(id2)[0].value = document.getElementById(id).innerHTML;
}

function subtract(id, id2){
  document.getElementById(id).innerHTML--;
  if(document.getElementById(id).innerHTML < 0){
    document.getElementById(id).innerHTML = 0;
  }
  document.getElementsByName(id2)[0].value = document.getElementById(id).innerHTML;;
}

function resetForm(){
  document.getElementById("numTacos").innerHTML = 0;
  document.getElementById("numBurritos").innerHTML = 0;
  document.getElementById("numEnchiladas").innerHTML = 0;
  document.getElementById("7Day").checked = true;
}
