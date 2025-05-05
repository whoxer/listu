// Armazena listas e tarefas
let lists = [];
let selectedListId = null;

// Elementos DOM
const listsContainer = document.getElementById("listsContainer");
const tasksSection = document.getElementById("tasksSection");
const selectedListTitle = document.getElementById("selectedListTitle");
const selectedListDescription = document.getElementById(
  "selectedListDescription"
);
const tasksContainer = document.getElementById("tasksContainer");
const addTaskBtn = document.getElementById("addTaskBtn");

// Formulário de nova lista
document.getElementById("newListForm").addEventListener("submit", (e) => {
  e.preventDefault();

  const title = document.getElementById("listTitle").value;
  const description = document.getElementById("listDescription").value;

  if (title) {
    const newList = {
      id: Date.now().toString(),
      title,
      description,
      tasks: [],
    };

    lists.push(newList);
    renderLists();
    e.target.reset();
  }
});

// Botão para adicionar tarefa
addTaskBtn.addEventListener("click", () => {
  if (!selectedListId) return;

  const taskText = prompt("Digite a nova tarefa:");
  if (taskText) {
    const list = lists.find((list) => list.id === selectedListId);
    if (list) {
      list.tasks.push({
        id: Date.now().toString(),
        text: taskText,
        completed: false,
      });
      renderTasks();
    }
  }
});

// Renderiza todas as listas
function renderLists() {
  listsContainer.innerHTML = "";

  lists.forEach((list) => {
    const listElement = document.createElement("div");
    listElement.className = `card list-card ${
      selectedListId === list.id ? "active" : ""
    }`;
    listElement.innerHTML = `
            <div class="card-body">
                <h5 class="card-title">${list.title}</h5>
                <p class="card-text text-muted">${
                  list.description || "Sem descrição"
                }</p>
            </div>
        `;

    listElement.addEventListener("click", () => selectList(list.id));
    listsContainer.appendChild(listElement);
  });
}

// Seleciona uma lista e mostra suas tarefas
function selectList(listId) {
  selectedListId = listId;
  const list = lists.find((list) => list.id === listId);

  if (list) {
    selectedListTitle.textContent = list.title;
    selectedListDescription.textContent = list.description || "Sem descrição";
    tasksSection.style.display = "block";
    renderTasks();
  }

  renderLists(); // Atualiza o destaque da lista selecionada
}

// Renderiza as tarefas da lista selecionada
function renderTasks() {
  tasksContainer.innerHTML = "";

  const list = lists.find((list) => list.id === selectedListId);
  if (!list) return;

  list.tasks.forEach((task) => {
    const taskElement = document.createElement("div");
    taskElement.className = "task-item";
    taskElement.innerHTML = `
            <input type="checkbox" ${task.completed ? "checked" : ""} 
                   onchange="toggleTaskCompletion('${list.id}', '${task.id}')">
            <span class="ms-2 ${
              task.completed ? "text-decoration-line-through" : ""
            }">
                ${task.text}
            </span>
        `;
    tasksContainer.appendChild(taskElement);
  });
}

// Alterna entre tarefa concluída/não concluída
window.toggleTaskCompletion = (listId, taskId) => {
  const list = lists.find((list) => list.id === listId);
  if (list) {
    const task = list.tasks.find((task) => task.id === taskId);
    if (task) {
      task.completed = !task.completed;
      renderTasks();
    }
  }
};
