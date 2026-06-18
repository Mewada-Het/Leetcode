import os
import re
import shutil
import requests

TOPIC_MAP = {
    "Array": "Arrays",
    "String": "Strings",
    "Hash Table": "Hash_Table",
    "Linked List": "Linked_List",
    "Tree": "Trees",
    "Binary Tree": "Trees",
    "Binary Search Tree": "Trees",
    "Graph": "Graphs",
    "Depth-First Search": "Graphs",
    "Breadth-First Search": "Graphs",
    "Dynamic Programming": "Dynamic_Programming",
    "Greedy": "Greedy",
    "Heap (Priority Queue)": "Heap_Priority_Queue",
    "Stack": "Stack",
    "Queue": "Queue",
    "Binary Search": "Binary_Search",
    "Sliding Window": "Sliding_Window",
    "Backtracking": "Backtracking",
    "Trie": "Trie",
    "Bit Manipulation": "Bit_Manipulation",
    "Two Pointers": "Two_Pointers",
    "Math": "Math",
    "Matrix": "Matrix",
    "Recursion": "Recursion",
    "Union Find": "Union_Find",
}

GRAPHQL_URL = "https://leetcode.com/graphql"


def slug_from_filename(filename):
    name = os.path.splitext(filename)[0]

    name = re.sub(r"^\d+[\.\-_ ]*", "", name)

    return (
        name.lower()
        .replace("_", "-")
        .replace(" ", "-")
    )


def fetch_topics(slug):
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        topicTags {
          name
        }
      }
    }
    """

    try:
        r = requests.post(
            GRAPHQL_URL,
            json={
                "query": query,
                "variables": {"titleSlug": slug}
            },
            timeout=10
        )

        data = r.json()

        question = data["data"]["question"]

        if not question:
            return []

        return [x["name"] for x in question["topicTags"]]

    except Exception:
        return []


for file in os.listdir("."):

    if not file.endswith(".cpp"):
        continue

    slug = slug_from_filename(file)

    topics = fetch_topics(slug)

    if not topics:
        continue

    for topic in topics:

        folder = TOPIC_MAP.get(topic)

        if not folder:
            continue

        os.makedirs(folder, exist_ok=True)

        shutil.copy2(
            file,
            os.path.join(folder, file)
        )

        print(f"{file} -> {folder}")