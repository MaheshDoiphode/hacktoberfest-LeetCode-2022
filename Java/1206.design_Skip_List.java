  // Sentinel
  //          \
  // level 3: -Inf ----------------------------> 4
  // level 2: -Inf ------------> 2 ------------> 4
  // level 1: -Inf ----> 1 ----> 2 ------------> 4
  // level 0: -Inf ----> 1 ----> 2 ----> 3 ----> 4 : this level is the most concrete level
  private static final double DEFAULT_PROB = 0.5;
  private final Random rand = new Random();
  private final List<Node> sentinels = new ArrayList<>();

  {
    sentinels.add(new Node(Integer.MIN_VALUE));
  }

  public boolean search(int target) {
    Node smallerOrEquals = getSmallerOrEquals(target);
    return smallerOrEquals.val == target;
  }

  public void add(int num) {
    Node cur = getSmallerOrEquals(num);
    // cur 最下层，比他小或者等于 num
    final Node toInsert = new Node(num);
    append(cur, toInsert);
    // populate the level
    populateLevelUp(toInsert);
  }

  private void populateLevelUp(final Node toInsert) {
    Node curPrev = toInsert.left, cur = toInsert;

    while (flipCoin()) {
      while (curPrev.left != null && curPrev.up == null) {
        curPrev = curPrev.left;
      }
      if (curPrev.up == null) {
        final Node newSentinel = new Node(Integer.MIN_VALUE);
        curPrev.up = newSentinel;
        newSentinel.down = curPrev;
        sentinels.add(curPrev.up);
      }
      curPrev = curPrev.up;
      final Node newNode = new Node(toInsert.val);
      cur.up = newNode;
      newNode.down = cur;
      cur = cur.up;
      curPrev.right = cur;
      cur.left = curPrev;
    }
  }

  private void append(Node prev, Node cur) {
    final Node next = prev.right;
    prev.right = cur;
    cur.left = prev;
    if (next != null) {
      next.left = cur;
      cur.right = next;
    }
  }

  public boolean erase(int num) {
    final Node toRemove = getSmallerOrEquals(num);
    if (toRemove.val != num) {
      return false;
    }
    Node cur = toRemove;
    while (cur != null) {
      final Node prev = cur.left, next = cur.right;
      prev.right = next;
      if (next != null) {
        next.left = prev;
      }
      cur = cur.up;
    }
    return true;
  }

  private Node getSmallerOrEquals(final int target) {
    Node cur = getSentinel();
    while (cur != null) {
      if (cur.right == null || cur.right.val > target) {
        if (cur.down == null) break;
        cur = cur.down;
      } else {
        cur = cur.right;
      }
    }
    return cur;
  }

  private boolean flipCoin() {
    return rand.nextDouble() < DEFAULT_PROB;
  }

  private Node getSentinel() {
    return sentinels.get(sentinels.size() - 1);
  }

  public String toString() {
    Node node = sentinels.get(0);
    final StringBuilder sb = new StringBuilder();
    while (node != null) {
      Node itr = node;
      while (itr != null) {
        sb.append(itr.val).append(",");
        itr = itr.up;
      }
      sb.append("\n");
      node = node.right;
    }
    return sb.toString();
  }

  private static final class Node {
    private final int val;
    private Node left, right, up, down;

    private Node(int val) {
      this.val = val;
    }
  }
