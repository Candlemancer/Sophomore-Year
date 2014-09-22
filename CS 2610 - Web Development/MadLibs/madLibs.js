var words = {};

// Add the value of the input element to the key-value object
// Where the key is the id of the element 
// and the value is the value. (Go figure.)
function updateObject(input) {

	words[input.id] = input.value;

	if(validateNumObjects()) document.getElementById("Submit").disabled = false;
	else document.getElementById("Submit").disabled = true;
}

// 24 Is the magic number of input elements
function validateNumObjects() {
	
	var count = 0;

	for (var key in words) {
		if(words.hasOwnProperty(key)) count++;
	}

	if (count >= 24) return true;
	else return false;
}


function reset() {

	document.getElementById("boxes").innerHTML = 
		  '<label>Plural Noun</label>'
		+ '<input id = "PluralNoun1" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Noun</label>'
		+ '<input id = "Noun1" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Noun</label>'
		+ '<input id = "Noun2" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Noun</label>'
		+ '<input id = "Noun3" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Noun</label>'
		+ '<input id = "Noun4" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Noun</label>'
		+ '<input id = "Noun5" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Sound</label>'
		+ '<input id = "Sound1" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Body Part</label>'
		+ '<input id = "BodyPart1" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Body Part</label>'
		+ '<input id = "BodyPart2" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Relationship</label>'
		+ '<input id = "Relationship1" 	type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Relationship</label>'
		+ '<input id = "Relationship2" 	type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Book Title</label>'
		+ '<input id = "BookTitle1" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Emotion ending in \'-ic\'</label>'
		+ '<input id = "Emotion1" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Place</label>'
		+ '<input id = "Place1" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Place</label>'
		+ '<input id = "Place2" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Musical Genre</label>'
		+ '<input id = "Genre1" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Adjective</label>'
		+ '<input id = "Adjective1" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Adjective</label>'
		+ '<input id = "Adjective2" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Adjective</label>'
		+ '<input id = "Adjective3" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Adjective</label>'
		+ '<input id = "Adjective4" 		type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Infinitive Verb</label>'
		+ '<input id = "InfinitiveVerb1" 	type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Infinitive Verb</label>'
		+ '<input id = "InfinitiveVerb2" 	type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Verb ending in \'-ing\'</label>'
		+ '<input id = "Verbing1" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
 		+ '<label>Verb ending in \'-ing\'</label>'
		+ '<input id = "Verbing2" 			type = "text" value = "" onchange = "updateObject(this)"/>'
		+ '<br/>'
		+ '<button id = "Submit" onclick= "generateMadLib()" >Go!</button>';

	document.getElementById("madLib").innerHTML = "";
	document.getElementById("Submit").disabled = true;

}


//Take all the inputs and make an actual mad lib from them.
function generateMadLib() {

	//Here's the actual Mad Lib
	if (true) {
		document.getElementById("madLib").style.textAlign = "left";
		document.getElementById("madLib").style.padding = "20px";
		document.getElementById("madLib").innerHTML =
		  "Here\'s to the " + words["PluralNoun1"] + ". <br/>"
		+ "the " + words["PluralNoun1"] + " who would rather spend their night with a " + words["Noun1"] + " or " 
		+ words["Sound1"] + " playing on their headphones than go to some " + words["Adjective1"] + " high school party. <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " whose 11:11 wish was wasted on " + words["Noun2"] + " who will " + words["InfinitiveVerb1"] + " them. <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " whose idea of a good night is " + words["Verbing1"] + " on the hood of a car, " + words["Verbing2"] + " the stars. <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who were never " + words["Adjective2"] + ", but were still " + words["Adjective3"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who care more about the " + words["Noun3"] + " than the " + words["Noun4"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who have crushes on a " + words["Noun5"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who have ever had a broken " + words["BodyPart1"] + " from their " + words["Relationship1"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who have read " + words["BookTitle1"] + " and didn\'t feel so " + words["Emotion1"] + " after doing so. <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who spend their days in " + words["Place1"] + " with their " + words["Relationship1"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who are straight up " + words["Adjective2"] + " and just don\'t care. <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who " + words["InfinitiveVerb2"] + " their " + words["BodyPart2"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + " who consider " + words["Genre1"] + " their lullaby for going to " + words["Place2"] + ". <br/>"
		+ "Here\'s to the " + words["PluralNoun1"] + ". <br/>";

		document.getElementById("boxes").innerHTML = "";
	}

}
