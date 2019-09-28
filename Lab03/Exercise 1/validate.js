function validate(){
  let password1 = document.getElementsByName("password1")[0].value;
  let password2 = document.getElementsByName("password2")[0].value;
  let count = 0;

  if(password1.length < 8){
    alert("Password is not long enough. It must be atleast 8 characters.");
  }else{
    count++;
  }
  if(password1 != password2){
    alert("Passwords do not match");
  }else{
    count++;
  }
  if(count > 1){
    alert("Password validated!");
  }
}
