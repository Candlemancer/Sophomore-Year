function area() {

	var area = (document.getElementById("length").value * document.getElementById("width").value);
	document.getElementById("area").value = area;

}

function add() {

	var valid1 = /^\d+$/.test(document.getElementById("value1").value);
	var valid2 = /^\d+$/.test(document.getElementById("value2").value);

	if (!valid1) { document.getElementById("value1E").innerHTML = "Please Enter a Valid Number"; }
	else 		 { document.getElementById("value1E").innerHTML = ""; }
	if (!valid2) { document.getElementById("value2E").innerHTML = "Please Enter a Valid Number"; }
	else 		 { document.getElementById("value2E").innerHTML = ""; }


	if (valid1 && valid2) {
		document.getElementById("stuffHeader").innerHTML = document.getElementById("value1").value + " + " 
			+ document.getElementById("value2").value + " = " + (parseFloat(document.getElementById("value1").value)
			+ parseFloat(document.getElementById("value2").value));
	}

}
