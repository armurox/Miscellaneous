let input = document.querySelector('input');
input.addEventListener('input', async function(){
    let response = await fetch('search?q=' + input.value);
    let shows = await response.json();
    let html = '';
    for (let id in shows){
        title = shows[id].title.replace('<', '&lt;').replace('&', '&amp;');
        html += '<li>' + title + '</li>';
    }

    document.querySelector('ul').innerHTML = html;
});